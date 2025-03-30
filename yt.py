# from pytube import Playlist, YouTube

# # Replace with your YouTube playlist URL
# playlist_url = "https://www.youtube.com/playlist?list=PLcbK387FUOqab1UXSFecGQYkDAcuhjFSE"

# # Create a Playlist object
# playlist = Playlist(playlist_url)

# print(f"Downloading Playlist: {playlist.title}")

# # Loop through video URLs in the playlist
# for video_url in playlist.video_urls:
#     try:
#         yt = YouTube(video_url)  # Create a YouTube object
#         print(f"Downloading: {yt.title}")
#         yt.streams.get_highest_resolution().download(output_path=r"D:\IntrdayHunter")
#         print("Download completed!")
#     except Exception as e:
#         print(f"Error downloading {video_url}: {e}")

# print("All videos have been downloaded successfully.")
