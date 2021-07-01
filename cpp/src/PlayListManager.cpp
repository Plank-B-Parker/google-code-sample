#include <vector>
#include <string>
#include <unordered_map>
#include "PlayListManager.h"

bool PlayListManager::add(std::string name, std::vector<std::string> playlist) {
	if (contains(name)) return 0;
	playLists.emplace(name, playlist);
	return 1;
}

bool PlayListManager::remove(std::string name)
{
	if (!contains(name)) return 0;
	playLists.erase(name);
	return 1;
}

bool PlayListManager::addVideo(std::string playlist, std::string vidId)
{
	std::vector<std::string> playList = playLists.find(playlist);
	for (auto id : playList) {
		if (id == vidId) {
			return 0;
		}
	}
	playList.emplace(vidId);
	return 1;
	//TODO: Check if playlist in list of playlists actually updates.
}

bool PlayListManager::removeVideo(std::string playlist, std::string vidId)
{
	std::vector<std::string> playList = playLists.find(playlist);
	for (std::vector<std::string>::iterator i = std::begin(playList); i != std::end(playList); ++i) {
		if (*i == vidId) {
			playList.erase(i);
			return 1;
		}
	}
	return 0;
}

std::vector<std::string> PlayListManager::getPlaylists()
{
	std::vector<Video> result;
	for (const auto& playlist : PlayLists) {
		result.emplace_back(playlist.first);
	}
	return result;
}

const std::vector<std::string>::iterator PlayListManager::getPlaylist(std::string name)
{
	const auto found = playLists.find(name);
	if (found == playLists.end()) {
		return nullptr;
	}
	else {
		return &(found->second);
	}
}

void PlayListManager::clear()
{
	playLists.clear();
}

bool PlayListManager::contains(std::string name)
{
	for (auto playlist : playLists) {
		if (compareStringsCaseInsensitive(name, playlist.first)) {
			return 1;
		}
	}
	return 0;
}





