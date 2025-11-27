#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <stack>
#include <cctype>

using namespace std;

int get_value(const string& s, map<string, int>& variables) {
    if (s[0] >= 'A' && s[0] <= 'Z') {
        return variables[s];
    } else {
        return stoi(s);
    }
}

bool eval_condition(const string& cond_str, map<string, int>& variables) {
    vector<string> operators = {"==", "!=", "<", ">"};
    string found_op;
    for (const string& op : operators) {
        if (cond_str.find(op) != string::npos) {
            found_op = op;
            break;
        }
    }
    if (found_op.empty()) {
        return false;
    }
    size_t pos = cond_str.find(found_op);
    string left_str = cond_str.substr(0, pos);
    string right_str = cond_str.substr(pos + found_op.length());
    // Trim spaces
    left_str.erase(0, left_str.find_first_not_of(" \t"));
    left_str.erase(left_str.find_last_not_of(" \t") + 1);
    right_str.erase(0, right_str.find_first_not_of(" \t"));
    right_str.erase(right_str.find_last_not_of(" \t") + 1);
    int left_val = get_value(left_str, variables);
    int right_val = get_value(right_str, variables);
    if (found_op == "==") {
        return left_val == right_val;
    } else if (found_op == "!=") {
        return left_val != right_val;
    } else if (found_op == "<") {
        return left_val < right_val;
    } else if (found_op == ">") {
        return left_val > right_val;
    }
    return false;
}

void execute_range(int start, int end, vector<string>& code_lines, vector<int>& depth, map<int, int>& end_map, map<string, int>& variables) {
    int i = start;
    while (i <= end) {
        string line = code_lines[i];
        istringstream iss(line);
        vector<string> tokens;
        string token;
        while (iss >> token) {
            tokens.push_back(token);
        }
        if (tokens.empty()) {
            i++;
            continue;
        }
        if (tokens[0] == "print") {
            string s = tokens[1];
            int val = get_value(s, variables);
            cout << val << endl;
            i++;
        } else if (tokens[0] == "if") {
            string cond_str = line.substr(2);
            cond_str.erase(0, cond_str.find_first_not_of(" \t"));
            bool result = eval_condition(cond_str, variables);
            int d = depth[i];
            int end_i = end_map[i];
            int no_index = -1;
            for (int j = i+2; j < end_i; j++) {
                if (depth[j] == d+1 && code_lines[j].find("No") != string::npos) {
                    no_index = j;
                    break;
                }
            }
            if (result) {
                if (no_index != -1) {
                    execute_range(i+2, no_index-1, code_lines, depth, end_map, variables);
                } else {
                    execute_range(i+2, end_i-1, code_lines, depth, end_map, variables);
                }
            } else {
                if (no_index != -1) {
                    execute_range(no_index+1, end_i-1, code_lines, depth, end_map, variables);
                }
            }
            i = end_i + 1;
        } else if (tokens[0] == "for") {
            string iter_var = tokens[1];
            int start_val = get_value(tokens[2], variables);
            int end_val = get_value(tokens[3], variables);
            int end_i = end_map[i];
            for (int k = start_val; k <= end_val; k++) {
                variables[iter_var] = k;
                execute_range(i+1, end_i-1, code_lines, depth, end_map, variables);
            }
            i = end_i + 1;
        } else {
            i++;
        }
    }
}

int main() {
    vector<string> lines;
    string line;
    while (getline(cin, line)) {
        if (line.empty()) continue;
        lines.push_back(line);
    }
    if (lines.size() < 2) {
        return 0;
    }
    int n = lines.size();
    vector<string> code_lines(lines.begin(), lines.end() - 2);
    string var_line = lines[n-2];
    string value_line = lines[n-1];
    map<string, int> variables;
    istringstream var_iss(var_line);
    istringstream val_iss(value_line);
    string var_name;
    int value;
    while (var_iss >> var_name) {
        if (val_iss >> value) {
            variables[var_name] = value;
        }
    }
    int code_size = code_lines.size();
    vector<int> depth(code_size, 0);
    int current_depth = 0;
    for (int i = 0; i < code_size; i++) {
        istringiss(code_lines[i]);
        vector<string> tokens;
        string token;
        while (iss >> token) {
            tokens.push_back(token);
        }
        depth[i] = current_depth;
        if (!tokens.empty()) {
            if (tokens[0] == "if" || tokens[0] == "for") {
                current_depth++;
            } else if (tokens[0] == "end") {
                current_depth--;
            }
        }
    }
    map<int, int> end_map;
    stack<int> stack;
    for (int i = 0; i < code_size; i++) {
        istringstream iss(code_lines[i]);
        string first;
        iss >> first;
        if (first == "if" || first == "for") {
            stack.push(i);
        } else if (first == "end") {
            if (!stack.empty()) {
                int start_i = stack.top();
                stack.pop();
                end_map[start_i] = i;
            }
        }
    }
    execute_range(0, code_size-1, code_lines, depth, end_map, variables);
    return 0;
}
