#include <SFML/Graphics.hpp>
#include <cmath>
#include <cstdlib>
#include <functional>

// Ôóíêöèÿ äëÿ îòðèñîâêè ãðàôèêà
void drawGraph(sf::RenderWindow& window, std::function<float(float)> func,
    float xMin, float xMax, float scaleX, float scaleY,
    sf::Color color) {
    sf::VertexArray graph(sf::LinesStrip);

    for (float x = xMin; x <= xMax; x += 0.1f) {
        float y = func(x); // Âû÷èñëåíèå çíà÷åíèÿ ôóíêöèè

        // Ïðåîáðàçîâàíèå êîîðäèíàò â ýêðàííûå
        float screenX = 400 + x * scaleX;
        float screenY = 300 - y * scaleY;

        // Äîáàâëåíèå òî÷êè â ìàññèâ âåðøèí
        graph.append(sf::Vertex(sf::Vector2f(screenX, screenY), color));
    }

    window.draw(graph);
}

int main() {
    // Ñîçäàíèå îêíà
    sf::RenderWindow window(sf::VideoMode(800, 600), "Ïðèëîæåíèå äëÿ âûâîäà ãðàôèêîâ");

    // Ïåðåìåííàÿ äëÿ õðàíåíèÿ ïîëüçîâàòåëüñêîé òî÷êè
    sf::CircleShape userPoint(5); // Ðàäèóñ 5 ïèêñåëåé
    userPoint.setFillColor(sf::Color::Red);
    bool userPointExists =
        false; // Ïåðåìåííàÿ äëÿ ïðîâåðêè ñóùåñòâîâàíèÿ ïîëüçîâàòåëüñêîé òî÷êè

    // 1 _ Çàãðóçêà øðèôòà (äîïèøèòå êîä)
    // ...
    // ...
    //
    //
    sf::Font font;
    font.loadFromFile("C:\\Windows\\Fonts\\arial.ttf");

    // 2 _ Òåêñò äëÿ îòîáðàæåíèÿ êîîðäèíàò òî÷êè (äîïèøèòå êîä)
    // Ðàçìåð òåêñòà 20, ïîëîæåíèå òåêñòà (10,10), öâåò áåëûé. Òåêñò õðàíèòå â
    // ïåðåìåííîé coordinatesText
    // ...
    // ...
    //
    sf::Text coordinatesText("", font, 20);
    coordinatesText.setPosition(10, 10);
    coordinatesText.setFillColor(sf::Color::White);

    // Îñè X è Y
    sf::VertexArray xAxis(sf::Lines, 2);
    xAxis[0].position = sf::Vector2f(50, 300);  // Íà÷àëî îñè X
    xAxis[0].color = sf::Color::White;          // Öâåò îñè
    xAxis[1].position = sf::Vector2f(750, 300); // Êîíåö îñè X
    xAxis[1].color = sf::Color::White;

    sf::VertexArray yAxis(sf::Lines, 2);
    yAxis[0].position = sf::Vector2f(400, 50);  // Íà÷àëî îñè Y
    yAxis[0].color = sf::Color::White;          // Öâåò îñè
    yAxis[1].position = sf::Vector2f(400, 550); // Êîíåö îñè Y
    yAxis[1].color = sf::Color::White;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            // Ïðîâåðêà êëèêà ìûøüþ
            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    // Ïîëó÷åíèå ïîçèöèè êëèêà
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);

                    // Ïðåîáðàçîâàíèå ýêðàííûõ êîîðäèíàò â "ìàòåìàòè÷åñêèå"
                    float mathX = (mousePos.x - 400) / 40.0f;  // Ìàñøòàá 30 ïî X
                    float mathY = -(mousePos.y - 300) / 40.0f; // Ìàñøòàá 100 ïî Y

                    // Óñòàíîâêà íîâîé ïîëüçîâàòåëüñêîé òî÷êè
                    userPoint.setPosition(mousePos.x - userPoint.getRadius(),
                        mousePos.y - userPoint.getRadius());
                    userPointExists = true; // Ïîìå÷àåì, ÷òî òî÷êà ñóùåñòâóåò

                    float y1 = 0.1f * mathX * mathX - 5;
                    float y2 = 0; // x = 0 ýòî âåðòèêàëüíàÿ ëèíèÿ

                    std::string zone;
                    
                    if (std::abs(mathX) < 0.01f) {
                        zone = "on the curve";
                    }
                    else if (std::abs(mathY - y1) < 0.1f) {
                        zone = "on the curve";
                    }
                    else if (mathY > y1 && mathX > 0) {
                        zone = "1";
                    }
                    else if (mathY > y1 && mathX < 0) {
                        zone = "3";
                    }
                    else if (mathY < y1 && mathX < 0) {
                        zone = "2";
                    }
                    else if (mathY < y1 && mathX > 0) {
                        zone = "4";
                    }
                    else {
                        zone = "5";
                    }

                    // Îáíîâëåíèå òåêñòà ñ êîîðäèíàòàìè òî÷êè
                    coordinatesText.setString("Coordinates: (" + std::to_string(mathX) +
                        ", " + std::to_string(mathY) +
                        ")\nZone: " + zone);
                }
            }
        }

        // 4 _ Î÷èñòêà ýêðàíà (äîïèøèòå êîä)
        window.clear(sf::Color::Black);

        //

        // Îòðèñîâêà îñåé
        window.draw(xAxis);
        window.draw(yAxis);

        // 5 _  Îòðèñîâêà ãðàôèêà y1 = 0.5*x (Çàìåíèòå íà âàø ãðàôèê)
        drawGraph(window, [](float x) { return 0.1f * x * x - 5; }, -10, 10, 40, 40, sf::Color::Red);

        
        sf::VertexArray xZero(sf::Lines, 2);
        xZero[0].position = sf::Vector2f(400, 0);
        xZero[1].position = sf::Vector2f(400, 600);
        xZero[0].color = sf::Color::Blue;
        window.draw(xZero);

        // Îòðèñîâêà ïîëüçîâàòåëüñêîé òî÷êè, åñëè îíà ñóùåñòâóåò
        if (userPointExists) {
            window.draw(userPoint);
            window.draw(coordinatesText);
        }

        // Îòîáðàæåíèå íîâîãî êàäðà
        window.display();
    }

    return 0;
}

