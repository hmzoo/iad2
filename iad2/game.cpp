#include "game.h"
//initialisation


const float Game::PlayerSpeed = 100.f;
const sf::Time Game::TimePerFrame = sf::seconds(1.f/60.f);


Game::Game()
: mWindow(sf::VideoMode(640,480),"SFML Application")
, mPlayer()
{

mPlayer.setRadius(20.f);
mPlayer.setPosition(100.f,100.f);
mPlayer.setFillColor(sf::Color ::Cyan);

}
//Boucle principale
void Game::run()
{

    sf::Clock clock;
    sf::Time timeSinceLastUpdate=sf::Time::Zero;
    while(mWindow.isOpen())
    {
        processEvents();
        sf::Time elapsedTime = clock.restart();
        timeSinceLastUpdate += elapsedTime;
        while(timeSinceLastUpdate > TimePerFrame){
            timeSinceLastUpdate-= TimePerFrame;
            processEvents();
            update(TimePerFrame);
        }
        render();
    }
}

//Gestion des commandes de l'utilisateur
void Game::processEvents()
{
    sf::Event event;
    while(mWindow.pollEvent(event))
    {
        switch(event.type){

    case sf::Event::KeyPressed:
        handlePlayerInput(event.key.code,true);
        break;
    case sf::Event::KeyReleased:
        handlePlayerInput(event.key.code,false);
        break;
    case sf::Event::Closed:
        mWindow.close();
        break;

        }

    }

}

//Gestion du clavier
void Game::handlePlayerInput(sf::Keyboard::Key key,bool ispressed){

    if(key==sf::Keyboard::Up){
        moveup=ispressed;
    }
    if(key==sf::Keyboard::Down){
        movedown=ispressed;
    }
    if(key==sf::Keyboard::Left){
        moveleft=ispressed;
    }
    if(key==sf::Keyboard::Right){
        moveright=ispressed;
    }


}

void Game::update(sf::Time elapsedTime)
{

    sf::Vector2f movement(0.f,0.f);
    if(moveup){movement.y-=PlayerSpeed;}
    if(movedown){movement.y=PlayerSpeed;}
    if(moveleft){movement.x-=PlayerSpeed;}
    if(moveright){movement.x=PlayerSpeed;}
    mPlayer.move(movement*elapsedTime.asSeconds());


}

void Game::render(){

mWindow.clear();
mWindow.draw(mPlayer);
mWindow.display();

}


