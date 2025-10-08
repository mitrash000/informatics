#include <SFML/Graphics.hpp>
#include <cmath>
#include <cstdlib>
#include <functional>

// ������� ��� ��������� �������
void drawGraph(sf::RenderWindow& window, std::function<float(float)> func,
    float xMin, float xMax, float scaleX, float scaleY,
    sf::Color color) {
    sf::VertexArray graph(sf::LinesStrip);

    for (float x = xMin; x <= xMax; x += 0.1f) {
        float y = func(x); // ���������� �������� �������

        // �������������� ��������� � ��������
        float screenX = 400 + x * scaleX;
        float screenY = 300 - y * scaleY;

        // ���������� ����� � ������ ������
        graph.append(sf::Vertex(sf::Vector2f(screenX, screenY), color));
    }

    window.draw(graph);
}

int main() {
    // �������� ����
    sf::RenderWindow window(sf::VideoMode(800, 600), "���������� ��� ������ ��������");

    // ���������� ��� �������� ���������������� �����
    sf::CircleShape userPoint(5); // ������ 5 ��������
    userPoint.setFillColor(sf::Color::Red);
    bool userPointExists =
        false; // ���������� ��� �������� ������������� ���������������� �����

    // 1 _ �������� ������ (�������� ���)
    // ...
    // ...
    //
    //
    sf::Font font;
    font.loadFromFile("C:\\Windows\\Fonts\\arial.ttf");

    // 2 _ ����� ��� ����������� ��������� ����� (�������� ���)
    // ������ ������ 20, ��������� ������ (10,10), ���� �����. ����� ������� �
    // ���������� coordinatesText
    // ...
    // ...
    //
    sf::Text coordinatesText("", font, 20);
    coordinatesText.setPosition(10, 10);
    coordinatesText.setFillColor(sf::Color::White);

    // ��� X � Y
    sf::VertexArray xAxis(sf::Lines, 2);
    xAxis[0].position = sf::Vector2f(50, 300);  // ������ ��� X
    xAxis[0].color = sf::Color::White;          // ���� ���
    xAxis[1].position = sf::Vector2f(750, 300); // ����� ��� X
    xAxis[1].color = sf::Color::White;

    sf::VertexArray yAxis(sf::Lines, 2);
    yAxis[0].position = sf::Vector2f(400, 50);  // ������ ��� Y
    yAxis[0].color = sf::Color::White;          // ���� ���
    yAxis[1].position = sf::Vector2f(400, 550); // ����� ��� Y
    yAxis[1].color = sf::Color::White;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            // �������� ����� �����
            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    // ��������� ������� �����
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);

                    // �������������� �������� ��������� � "��������������"
                    float mathX = (mousePos.x - 400) / 30.0f;  // ������� 30 �� X
                    float mathY = -(mousePos.y - 300) / 100.0f; // ������� 100 �� Y

                    // ��������� ����� ���������������� �����
                    userPoint.setPosition(mousePos.x - userPoint.getRadius(),
                        mousePos.y - userPoint.getRadius());
                    userPointExists = true; // ��������, ��� ����� ����������

                    float y1 = 0.1f * mathX * mathX - 5;
                    float y2 = 0; // x = 0 ��� ������������ �����

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

                    // ���������� ������ � ������������ �����
                    coordinatesText.setString("Coordinates: (" + std::to_string(mathX) +
                        ", " + std::to_string(mathY) +
                        ")\nZone: " + zone);
                }
            }
        }

        // 4 _ ������� ������ (�������� ���)
        window.clear(sf::Color::Black);

        //

        // ��������� ����
        window.draw(xAxis);
        window.draw(yAxis);

        // 5 _  ��������� ������� y1 = 0.5*x (�������� �� ��� ������)
        drawGraph(window, [](float x) { return 0.1f * x * x - 5; }, -10, 10, 30, 100, sf::Color::Red);

        
        sf::VertexArray xZero(sf::Lines, 2);
        xZero[0].position = sf::Vector2f(400, 0);
        xZero[1].position = sf::Vector2f(400, 600);
        xZero[0].color = sf::Color::Blue;
        window.draw(xZero);

        // ��������� ���������������� �����, ���� ��� ����������
        if (userPointExists) {
            window.draw(userPoint);
            window.draw(coordinatesText);
        }

        // ����������� ������ �����
        window.display();
    }

    return 0;
}
