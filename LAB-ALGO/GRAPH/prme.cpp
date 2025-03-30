#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <random>
#include <cmath>
#include <string>
#include <sstream>

using namespace std;

class PRME {
public:
    PRME(int dim, float lr, float lambda, float margin, const string& train_file)
        : dim(dim), lr(lr), lambda(lambda), margin(margin) {
        read_data(train_file);
        initialize_embeddings();
    }

    void train(int epochs) {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<int> item_dist(0, num_items - 1);

        for (int epoch = 0; epoch < epochs; ++epoch) {
            float total_loss = 0.0;
            int num_pairs = train_pairs.size();

            for (const auto& pair : train_pairs) {
                int u = pair.first;
                int i = pair.second;

                // Sample negative item j
                int j = sample_negative_item(u, gen, item_dist);

                vector<float>& u_emb = user_embeddings[u];
                vector<float>& i_emb = item_embeddings[i];
                vector<float>& j_emb = item_embeddings[j];

                float d_ui = squared_distance(u_emb, i_emb);
                float d_uj = squared_distance(u_emb, j_emb);
                float loss = max(0.0f, d_ui - d_uj + margin);
                total_loss += loss;

                if (loss > 0) {
                    for (int k = 0; k < dim; ++k) {
                        // Compute gradients
                        float grad_u = 2 * (j_emb[k] - i_emb[k]) + lambda * u_emb[k];
                        float grad_i = 2 * (i_emb[k] - u_emb[k]) + lambda * i_emb[k];
                        float grad_j = 2 * (u_emb[k] - j_emb[k]) + lambda * j_emb[k];

                        // Update embeddings
                        u_emb[k] -= lr * grad_u;
                        i_emb[k] -= lr * grad_i;
                        j_emb[k] -= lr * grad_j;
                    }
                } else {
                    // Only regularization
                    for (int k = 0; k < dim; ++k) {
                        u_emb[k] -= lr * lambda * u_emb[k];
                        i_emb[k] -= lr * lambda * i_emb[k];
                        j_emb[k] -= lr * lambda * j_emb[k];
                    }
                }
            }

            cout << "Epoch " << epoch + 1 << ", Loss: " << total_loss / num_pairs << endl;
        }
    }

private:
    int dim;
    float lr, lambda, margin;
    int num_users, num_items;
    vector<vector<float>> user_embeddings;
    vector<vector<float>> item_embeddings;
    vector<pair<int, int>> train_pairs;
    vector<unordered_set<int>> user_pos_items;

    void read_data(const string& train_file) {
        ifstream file(train_file);
        string line;

        unordered_map<string, int> user_to_idx;
        unordered_map<string, int> item_to_idx;
        int user_idx = 0, item_idx = 0;

        // First pass to collect all users and items
        while (getline(file, line)) {
            stringstream ss(line);
            string user_id, item_id;
            ss >> user_id >> item_id;

            if (!user_to_idx.count(user_id)) user_to_idx[user_id] = user_idx++;
            if (!item_to_idx.count(item_id)) item_to_idx[item_id] = item_idx++;
        }

        num_users = user_to_idx.size();
        num_items = item_to_idx.size();
        user_pos_items.resize(num_users);

        // Reset file stream
        file.clear();
        file.seekg(0);

        // Second pass to build training pairs
        while (getline(file, line)) {
            stringstream ss(line);
            string user_id, item_id;
            ss >> user_id >> item_id;

            int u = user_to_idx[user_id];
            int i = item_to_idx[item_id];
            train_pairs.emplace_back(u, i);
            user_pos_items[u].insert(i);
        }
    }

    void initialize_embeddings() {
        random_device rd;
        mt19937 gen(rd());
        normal_distribution<float> dist(0.0, 0.01);

        user_embeddings.resize(num_users, vector<float>(dim));
        item_embeddings.resize(num_items, vector<float>(dim));

        for (auto& vec : user_embeddings)
            for (float& val : vec)
                val = dist(gen);

        for (auto& vec : item_embeddings)
            for (float& val : vec)
                val = dist(gen);
    }

    int sample_negative_item(int user, mt19937& gen, uniform_int_distribution<int>& item_dist) {
        const auto& pos = user_pos_items[user];
        int j;
        int attempts = 0;
        do {
            j = item_dist(gen);
            if (++attempts > 1000) break; // Avoid infinite loop
        } while (pos.count(j));
        return j;
    }

    float squared_distance(const vector<float>& a, const vector<float>& b) {
        float dist = 0.0;
        for (int k = 0; k < dim; ++k) {
            float diff = a[k] - b[k];
            dist += diff * diff;
        }
        return dist;
    }
};

int main() {
    PRME model(50, 0.01, 0.001, 1.0, "train_data.txt");
    model.train(10);
    return 0;
}
