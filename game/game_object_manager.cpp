#include "stdafx.h"
#include "game_object_manager.h"
#include "game.h"

GameObjectManager::GameObjectManager() {}

GameObjectManager::~GameObjectManager() {
    std::for_each(_game_objects.begin(), _game_objects.end(), 
        GameObjectDeallocator());
}

void GameObjectManager::Add(std::size_t number, Player* game_object) {
    _game_objects.insert(
        std::pair<std::size_t, Player*>(number, game_object)
    );
}

void GameObjectManager::Remove(std::size_t number) {
    std::map<std::size_t, Player*>::iterator results =
        _game_objects.find(number);
    if (results != _game_objects.end()) {
        delete results->second;
        _game_objects.erase(results);
    }
}

Player* GameObjectManager::Get(std::size_t number) const {
    std::map<std::size_t, Player*>::const_iterator results =
        _game_objects.find(number);
    if (results == _game_objects.end()) {
        return NULL;
    }
    return results->second;
}

int GameObjectManager::GetObjectCount() const {
    return _game_objects.size();
}

void GameObjectManager::DrawAll(sf::RenderWindow& render_window) {
    std::map<std::size_t, Player*>::const_iterator itr =
        _game_objects.begin();
    while (itr != _game_objects.end()) {
        itr->second->Draw(render_window);
        itr++;
    }
}

// Clock resets between frame updates
sf::Clock GameObjectManager::_clock;
