#include <SFML/Graphics.hpp>
//#include<SFML/Audio.hpp>
#include<iostream>
using namespace std;
int main(){
    //sf::Music music;
    //music.openFromFile("pirates.wav");
    enum Direction{Down,Left,Right,Up};
    sf::Vector2i source(2,Down);
    sf::RenderWindow window(sf::VideoMode(640,480),"Jack Sparrow");
    window.setKeyRepeatEnabled(false);
    sf::Texture pTexture;
    sf::Sprite playerImage;
    sf::Sprite playerImage2;
    sf::Clock clock;
    float frameCounter,switchFrame=100,frameSpeed=500;
    if(!pTexture.loadFromFile("player.png"))
       cout<<"Error could not load player image " <<endl;
    sf::Texture jTexture;
    sf::Sprite jungleImage;
    if(!jTexture.loadFromFile("pirate.png")){
        cout<<"sorry"<<endl;
    }
    sf::Texture aTexture;
    if(!aTexture.loadFromFile("antagonist.png"))
        cout<<"Could not load antagonist image "<<endl;

    sf::Sprite barbosa;
    /*
    if(!pTexture.loadFromFile("player.png",sf::IntRect(0,0,32,48)))//image being 128*192 consisting of 16 images
        cout<<"Error could not load player image "<<endl;
    if(!pTexture.loadFromFile("antagonist.png",sf::IntRect(0,128,64,64)))//1st two para speciefies point to start cropping...
        cout<<"Error could not load player image"<<endl;
    */
    playerImage.setPosition(100,100);
    sf::RectangleShape rectangle(sf::Vector2f(640.0f,10.0f));
    rectangle.setFillColor(sf::Color::Red);
    rectangle.setPosition(0,0);
    sf::RectangleShape rectangle2(sf::Vector2f(10.0f,480.0f));
    rectangle2.setFillColor(sf::Color::Red);
    rectangle2.setPosition(630,0);
    sf::RectangleShape rectangle3(sf::Vector2f(10.0f,480.0f));
    rectangle3.setFillColor(sf::Color::Red);
    rectangle3.setPosition(0,10);
    sf::RectangleShape rectangle4(sf::Vector2f(640.0f,10.0f));
    rectangle4.setFillColor(sf::Color::Red);
    rectangle4.setPosition(0,470);
    playerImage.setTexture(pTexture);
    playerImage2.setTexture(pTexture);
    barbosa.setTexture(aTexture);
    jungleImage.setTexture(jTexture);
    playerImage.setPosition(320,240);
    playerImage2.setPosition(50,20);
    barbosa.setPosition(100,100);
    while(window.isOpen()){
        sf::Event event;
        while(window.pollEvent(event)){
        switch (event.type){
            case sf::Event::Closed:
                window.close();
                break;
            //case sf::Event::KeyPressed:
                //if(event.key.code==sf::Keyboard::Return)
                    //music.play();
            }
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
            source.y=Up;
            if(playerImage.getGlobalBounds().intersects(rectangle.getGlobalBounds()))
                playerImage.move(0,0);
            else
                playerImage.move(0,-0.25);
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
            source.y=Down;
            if(playerImage.getGlobalBounds().intersects(rectangle4.getGlobalBounds()))
                playerImage.move(0,0);
            else
                playerImage.move(0,0.25);
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
            source.y=Left;
            if(playerImage.getGlobalBounds().intersects(rectangle3.getGlobalBounds()))
                playerImage.move(0,0);
            else
                playerImage.move(-0.25,0);
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
            source.y=Right;
            if(playerImage.getGlobalBounds().intersects(rectangle2.getGlobalBounds()))
                playerImage.move(0,0);
            else
                playerImage.move(0.25,0);
        }
        if(playerImage.getGlobalBounds().intersects(barbosa.getGlobalBounds())){
            cout<<"dont mess with Barbosa "<<endl;
            playerImage.move(0,0);
        }
        else if(playerImage.getGlobalBounds().intersects(playerImage2.getGlobalBounds())){
            cout<<"collision "<<endl;
            playerImage.move(0,0);
        }
        frameCounter+=frameSpeed*clock.restart().asSeconds();
        if(frameCounter>=switchFrame){
            source.x++;
            frameCounter=0;
            if(source.x*32>=pTexture.getSize().x)
                source.x=0;
        }
        jungleImage.setTextureRect(sf::IntRect(0,0,640,480));
        playerImage.setTextureRect(sf::IntRect(source.x*32,source.y*48,32,48));
        playerImage2.setTextureRect(sf::IntRect(0,0,32,48));
        barbosa.setTextureRect(sf::IntRect(0,128,64,64));
    window.clear(sf::Color(200,0,100,0));
    window.draw(jungleImage);
    window.draw(rectangle);
    window.draw(rectangle2);
    window.draw(rectangle3);
    window.draw(rectangle4);
    window.draw(playerImage2);
    window.draw(barbosa);
    window.draw(playerImage);
    window.display();

    }
    return 0;
}
