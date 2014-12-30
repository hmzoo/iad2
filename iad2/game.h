#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>

class Game
{
   public:
                            Game();
        void                run();
    private:
        void                processEvents();
        void                update(sf::Time elapsedTime);
        void                render();
        void                handlePlayerInput(sf::Keyboard::Key key,bool ispressed);

    private:
        static const float		PlayerSpeed;
		static const sf::Time	TimePerFrame;
        bool                moveup;
        bool                movedown;
        bool                moveleft;
        bool                moveright;

        sf::RenderWindow    mWindow;
        sf::CircleShape     mPlayer;
};

#endif // GAME_H
