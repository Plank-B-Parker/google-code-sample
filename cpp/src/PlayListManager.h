#pragma once
#include <vector>
#include <string>
#include <unordered_map>
#include "helper.h"

class PlayListManager {
private:
	std::unordered_map<std::string, std::vector<std::string>> playLists;
public:
	bool add(std::string name, std::vector<std::string> playlist);
	bool remove(std::string name);
	bool addVideo(std::string playlist, std::string vidId);
	bool removeVideo(std::string playlist, std::string vidId);
	std::vector<std::string> getPlaylists();
	const std::vector<std::string>::iterator getPlaylist(std::string name);
	bool contains(std::string name);
	void clear();
};