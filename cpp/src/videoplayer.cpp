#include "videoplayer.h"

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "video.h"
#include "helper.h"

void VideoPlayer::numberOfVideos() {
  std::cout << mVideoLibrary.getVideos().size() << " videos in the library"
            << std::endl;
}

void VideoPlayer::showAllVideos() {
    std::vector<Video> videos = mVideoLibrary.getVideos();
    for (auto video : videos) {
        std::cout << video.getTitle() << " (" << video.getVideoId() << ") " << "[ ";
        
        for (auto tag: video.getTags()) {
            std::cout << tag << " ";
        }

        std::cout << "]" << std::endl;
        
    }
}

void VideoPlayer::playVideo(const std::string& videoId) {
    const Video* newVid = mVideoLibrary.getVideo(videoId);
    if (newVid == nullptr) {
        std::cout << "Cannot play video: Video does not exist" << std::endl;
        return;
    }
    if (playingVidId != "") {
        std::cout << "Stopping video: " << mVideoLibrary.getVideo(playingVidId)->getTitle() << std::endl;
    }
    
    std::cout << "Playing video: " << newVid->getTitle() << std::endl;
    playingVidId = newVid->getVideoId();
    paused = false;
}

void VideoPlayer::stopVideo() {
    if (playingVidId == "") {
        std::cout << "Cannot stop video: No video is currently playing" << std::endl;
        return;
    }
    std::cout << "Stopping video: " << mVideoLibrary.getVideo(playingVidId)->getTitle() << std::endl;
    playingVidId = "";
}

void VideoPlayer::playRandomVideo() {
    std::srand(std::time(0));
    int index = rand() % (mVideoLibrary.numVids-1);
    std::vector<Video> videos = mVideoLibrary.getVideos();

    playVideo(videos[index].getVideoId());
}

void VideoPlayer::pauseVideo() {
    if (playingVidId == "") {
        std::cout << "No video playing to be paused" << std::endl;
        return;
    }
    if (paused) {
        std::cout << "Video already paused" << std::endl;
        return;
    }
    paused = true;
    std::cout << "Pausing Video: " << mVideoLibrary.getVideo(playingVidId)->getTitle() << std::endl;
}

void VideoPlayer::continueVideo() {
    if (playingVidId == "") {
        std::cout << "No video to continue" << std::endl;
        return;
    }
    if (!paused) {
        std::cout << "Not paused, can't continue" << std::endl;
        return;
    }
    paused = false;
    std::cout << "Playing video: " << mVideoLibrary.getVideo(playingVidId)->getTitle() << std::endl;
}

void VideoPlayer::showPlaying() {
    if (playingVidId == "") {
        std::cout << "No video playing" << std::endl;
        return;
    }
    Video video = *mVideoLibrary.getVideo(playingVidId);
    std::cout << "Currently playing: " << video.getTitle() << " [ ";
    for (auto tag : video.getTags()) {
        std::cout << tag << " ";
    }
    if (paused) {
        std::cout << "- PAUSED";
    }
    std::cout << std::endl;
}

void VideoPlayer::createPlaylist(const std::string& playlistName) {
    if (playlists.contains(playlistName)) {
        std::cout << "Playlist already exists" << std::endl;
        return;
    }
    playlists.add(playlistName);
    std::cout << "Successfully created playlist: " << playlistName << std::endl;
}

void VideoPlayer::addVideoToPlaylist(const std::string& playlistName,
                                     const std::string& videoId) {
    if (!playlists.contains(playlistName)) {
        std::cout << "Playlist not found" << std::endl;
        return;
    }
    if (!playlists.addVideo(playlistName, videoId)) {
        std::cout << "Video already in playlist" << std::endl;
        return;
    };
    std::cout<< mVideoLibrary.getVideo(videoId)->getTitle << "successfully added to " << playlistName << std::endl;
}

void VideoPlayer::showAllPlaylists() {
    std::vector<std::string> names = playlists.getPlaylists;
    std::cout << "Showing all playlists" << std::endl;
    for (auto playlist : names) {
        std::cout << " " << playlist << std::endl;
    }
}

void VideoPlayer::showPlaylist(const std::string& playlistName) {
    std::vector<std::string>::iterator ids = playlists.getPlaylist(playlistName);
    if (ids == nullptr) {
        std::cout << "Playlist does not exist"<< std::endl;
    }
    std::cout << "Showing playlist: " << playlistName << ": " << std::endl;
    if (*ids.size == 0) {
        std::cout << "No videos in playlist" << std::endl;
    }
    for (auto id : *ids) {
        std::cout << " " << mVideoLibrary.getVideo(id)->getTitle() << std::endl;
    }
}

void VideoPlayer::removeFromPlaylist(const std::string& playlistName,
                                     const std::string& videoId) {
    if (!playlists.contains(playlistName)) {
        std::cout << "Playlist does not exist"<< std::endl;
        return;
    }
    if (!playlists.removeVideo(playlistName, videoId)) {
        std::cout << "Video doesnt exist in playlist" << std::endl;
    }
    
    std::cout << mVideoLibrary.getVideo(videoId)->getTitle() << " successfully removed from " << playlistName << std::endl;
}

void VideoPlayer::clearPlaylist(const std::string& playlistName) {
    playlists.clear();
    std::cout << "Playlist cleared" << std::endl;
}

void VideoPlayer::deletePlaylist(const std::string& playlistName) {
    if (!playlists.remove(playlistName)) {
        std::cout << "Playlist doesn't exist" << std::endl;
    }
    std::cout << "Playlist deleted" << std::endl;
}

void VideoPlayer::searchVideos(const std::string& searchTerm) {
  std::cout << "searchVideos needs implementation" << std::endl;
}

void VideoPlayer::searchVideosWithTag(const std::string& videoTag) {
  std::cout << "searchVideosWithTag needs implementation" << std::endl;
}

void VideoPlayer::flagVideo(const std::string& videoId) {
  std::cout << "flagVideo needs implementation" << std::endl;
}

void VideoPlayer::flagVideo(const std::string& videoId, const std::string& reason) {
  std::cout << "flagVideo needs implementation" << std::endl;
}

void VideoPlayer::allowVideo(const std::string& videoId) {
  std::cout << "allowVideo needs implementation" << std::endl;
}
