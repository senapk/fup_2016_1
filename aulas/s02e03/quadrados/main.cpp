#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

using namespace std;

struct Elemento{
    int x;
    int y;
    int xold;
    int yold;
    sf::Color cor;
};

int main()
{
    int casa = 128;
    int ncol = 3;
    int nlin = 3;
    int largura = ncol * casa;
    int altura = nlin * casa;

    sf::Texture tex_py;
    tex_py.loadFromFile("../quadrados/pikachu.png");
    sf::Sprite sprite_py(tex_py);

    sf::RectangleShape carimbo;
    carimbo.setSize(sf::Vector2f(casa, casa));

    Elemento py;
    py.x = 0 * casa;
    py.y = 0 * casa;
    py.cor = sf::Color::Yellow;

    Elemento pedra;
    pedra.x = 0 * casa;
    pedra.y = 1 * casa;
    pedra.cor = sf::Color::White;

    Elemento fruta;
    fruta.x = 0 * casa;
    fruta.y = 2 * casa;
    fruta.cor = sf::Color::Red;

    Elemento poste;
    poste.x = 2 * casa;
    poste.y = 2 * casa;
    poste.cor = sf::Color::Green;

    sf::RenderWindow janela(sf::VideoMode(ncol * casa, nlin * casa), "Super");
    while(janela.isOpen()){
        //inicio
        py.xold = py.x;
        py.yold = py.y;

        sf::Event evento;
        while(janela.pollEvent(evento)){
            if(evento.type == sf::Event::Closed){
                janela.close();
            }
            if(evento.type == sf::Event::KeyPressed){
                if(evento.key.code == sf::Keyboard::Right){
                    py.x += casa;
                }
                if(evento.key.code == sf::Keyboard::Down){
                    py.y += casa;
                }
                if(evento.key.code == sf::Keyboard::Left){
                    py.x -= casa;
                }
                if(evento.key.code == sf::Keyboard::Up){
                    py.y -= casa;
                }
            }
        }

        //inicio
        if(py.x == largura || py.x < 0 ||
           py.y == altura || py.y < 0){
           py.x = py.xold;
           py.y = py.yold;
        }

        if(py.x == poste.x && py.y == poste.y){
            py.y = py.yold;
            py.x = py.xold;
        }

        if(py.x == fruta.x && py.y == fruta.y){
            do{
                fruta.x = (rand() % ncol) * casa;
                fruta.y = (rand() % nlin) * casa;
            }while(fruta.x == poste.x && fruta.y == poste.y);
        }


        //fim

        janela.clear();



        //pintando bloco
        carimbo.setPosition(pedra.x, pedra.y);
        carimbo.setFillColor(pedra.cor);
        janela.draw(carimbo);

        //pintando o poste
        carimbo.setPosition(poste.x, poste.y);
        carimbo.setFillColor(poste.cor);
        janela.draw(carimbo);

        carimbo.setPosition(fruta.x, fruta.y);
        carimbo.setFillColor(fruta.cor);
        janela.draw(carimbo);

        //pintando py
        sprite_py.setPosition(py.x, py.y);
        //carimbo.setFillColor(py.cor);
        janela.draw(sprite_py);

        janela.display();
    }
    return 0;
}










