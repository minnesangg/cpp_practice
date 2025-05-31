#include <iostream>
#include <memory>

class Enemy{
public:
    virtual void attack() = 0;
    virtual ~Enemy() = default;
};

class Goblin : public Enemy{
public:
    void attack() override{
        std::cout << "Goblin is attacking!" << std::endl;
    }
};

class Dragon : public Enemy{
public:
    void attack() override{
        std::cout << "Dragon is attacking" << std::endl;
    }
};

class Orc : public Enemy{
public:
    void attack() override{
        std::cout << "Orc is attacking" << std::endl;
    }
};

class Spawner{
public:
    virtual std::unique_ptr<Enemy> spawnEnemy() = 0;
    virtual ~Spawner() = default;
};

class GoblinSpawner : public Spawner{
public:
    std::unique_ptr<Enemy> spawnEnemy() override{
        return std::make_unique<Goblin>();
    }
};

class DragonSpawner : public Spawner{
public:
    std::unique_ptr<Enemy> spawnEnemy() override{
        return std::make_unique<Dragon>();
    }
};

class OrcSpawner : public Spawner{
public:
    std::unique_ptr<Enemy> spawnEnemy() override{
        return std::make_unique<Orc>();
    }
};

void gameLogic(Spawner& spawner){
    auto enemy = spawner.spawnEnemy();
    enemy->attack();
}

int main(){
    GoblinSpawner goblinFactory;
    DragonSpawner dragonFactory;
    OrcSpawner orcFactory;

    gameLogic(goblinFactory);
    gameLogic(dragonFactory);
    gameLogic(orcFactory);
}