#include<SFML/Audio.hpp>
#include<SFML/System.hpp>
#include<SFML/Network.hpp>
#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<vector>
#include<math.h>
#include"ball.cpp"
#include"hole.cpp"
#include"barrier.cpp"
#include"mouse.cpp"
#include"physics.cpp"

sf::Event ev;
sf::Clock deltaTime;
sf::Clock winClock;
sf::Clock endClock;
sf::Color color;
sf::RenderWindow window(sf::VideoMode(960, 540), "Golf game", sf::Style::Resize|sf::Style::Titlebar|sf::Style::Close);

bool inLevel = false;
bool levelscreen = false;
bool game_over = false;

bool showWin1 = false;
bool showWin2 = false;
bool showWin3 = false;
bool showWin4 = false;
bool showWin5 = false;
bool showWin6 = false;

bool lock2 = false;
bool lock3 = false;
bool lock4 = false;
bool lock5 = false;
bool lock6 = false;

int level = 0;
int count = 0;

Mouse mouse;

//level1 objects
Ball ball1(10.f, 100.f, 100.f, 0.f, 0.f, 0.f, 0.f, 0.27f);
Hole hole1(18.f, 750.f, 350.f);

//level2 objects
Ball ball2(10.f, 100.f, 150.f, 0.f, 0.f, 0.f, 0.f, 0.3f);
Hole hole2(17.f, 850.f, 270.f);
Barrier bar2(30.f, 100.f, 300.f, 0.f, 0.f, 20.f);

//level3 objects
Ball ball3(10.f, 50.f, 300.f, 0.f, 0.f, 0.f, 0.f, 0.3f);
Hole hole3(16.5f, 850.f, 300.f);
Barrier bar3(30.f, 100.f, 250.f, 0.f, 0.f, 30.f);
Barrier bar3_1(30.f, 100.f, 550.f, 0.f, 0.f, 45.f);

//level4 objects
Ball ball4(10.f, 50.f, 250.f, 0.f, 0.f, 0.f, 0.f, 0.3f);
Hole hole4(15.5f, 900.f, 450.f);
Barrier bar4(40.f, 100.f, 150.f, 0.f, 0.f, 45.f);
Barrier bar4_1(40.f, 100.f, 450.f, 440.f, 0.f, 50.f);
Barrier bar4_2(40.f, 100.f, 750.f, 0.f, 0.f, 50.f);

//level5 objects
Ball ball5(10.f, 50.f, 250.f, 0.f, 0.f, 0.f, 0.f, 0.3f);
Hole hole5(15.5f, 900.f, 450.f);
Barrier bar5(35.f,100.f,250.f,0.f,0.f,50.f);
Barrier bar5_1(35.f,100.f,600.f,0.f,0.f,60.f);
Barrier bar5_2(100.f,35.f,100.f,100.f,50.f,0.f);
Barrier bar5_3(100.f,35.f,100.f,450.f,45.f,0.f);

//level6 objects
Ball ball6(10.f, 50.f, 250.f, 0.f, 0.f, 0.f, 0.f, 0.3f);
Hole hole6(15.5f, 900.f, 350.f);
Barrier bar6(35.f,100.f,250.f,0.f,0.f,45.f);
Barrier bar6_1(35.f,100.f,500.f,0.f,0.f,50.f);
Barrier bar6_2(35.f,100.f,750.f,0.f,0.f,55.f);
Barrier bar6_3(100.f,35.f,150.f,150.f,45.f,0.f);
Barrier bar6_4(100.f, 35.f, 850.f, 450.f, 50.f, 0.f);

void level_screen(Mouse& mouse) {
	//6 level
	Barrier box1(128, 72, 144, 132, 0, 0);
	Barrier box2(128, 72, 416, 132, 0, 0);
	Barrier box3(128, 72, 688, 132, 0, 0);
	Barrier box4(128, 72, 144, 336, 0, 0);
	Barrier box5(128, 72, 416, 336, 0, 0);
	Barrier box6(128, 72, 688, 336, 0, 0);

	window.clear(sf::Color::Green);

	box1.setColor(color.Blue);
	box2.setColor(color.Blue);
	box3.setColor(color.Blue);
	box4.setColor(color.Blue);
	box5.setColor(color.Blue);
	box6.setColor(color.Blue);

	box1.renderBarrier(window);
	box2.renderBarrier(window);
	box3.renderBarrier(window);
	box4.renderBarrier(window);
	box5.renderBarrier(window);
	box6.renderBarrier(window);

	sf::Font font;
	if (!font.loadFromFile("fonts/Dee-Quickest Sans.otf")) {
		std::cerr << "Hata olustu!";
	}
	sf::Text text1;
	text1.setFont(font);
	text1.setCharacterSize(45);
	text1.setFillColor(sf::Color::Black);
	text1.setStyle(sf::Text::Bold);
	text1.setPosition(195, 145);
	text1.setString(std::to_string(1));
	window.draw(text1);

	sf::Text text2;
	text2.setFont(font);
	text2.setCharacterSize(45);
	text2.setFillColor(sf::Color::Black);
	text2.setStyle(sf::Text::Bold);
	text2.setPosition(467, 145);
	text2.setString(std::to_string(2));
	window.draw(text2);

	sf::Text text3;
	text3.setFont(font);
	text3.setCharacterSize(45);
	text3.setFillColor(sf::Color::Black);
	text3.setStyle(sf::Text::Bold);
	text3.setPosition(739, 145);
	text3.setString(std::to_string(3));
	window.draw(text3);

	sf::Text text4;
	text4.setFont(font);
	text4.setCharacterSize(45);
	text4.setFillColor(sf::Color::Black);
	text4.setStyle(sf::Text::Bold);
	text4.setPosition(195, 349);
	text4.setString(std::to_string(4));
	window.draw(text4);

	sf::Text text5;
	text5.setFont(font);
	text5.setCharacterSize(45);
	text5.setFillColor(sf::Color::Black);
	text5.setStyle(sf::Text::Bold);
	text5.setPosition(467, 349);
	text5.setString(std::to_string(5));
	window.draw(text5);

	sf::Text text6;
	text6.setFont(font);
	text6.setCharacterSize(45);
	text6.setFillColor(sf::Color::Black);
	text6.setStyle(sf::Text::Bold);
	text6.setPosition(739, 349);
	text6.setString(std::to_string(6));
	window.draw(text6);

	sf::Texture texture1;
	texture1.loadFromFile("photos/kilit.png");

	
	sf::Sprite spr2;
	spr2.setTexture(texture1);
	spr2.setPosition(437, 130);
	spr2.setScale(.09f, .09f);
	if (!lock2) {
		window.draw(spr2);
	}

	sf::Sprite spr3;
	spr3.setTexture(texture1);
	spr3.setPosition(709, 130);
	spr3.setScale(.09f, .09f);
	if (!lock3) {
	    window.draw(spr3);
	}

	sf::Sprite spr4;
	spr4.setTexture(texture1);
	spr4.setPosition(165, 334);
	spr4.setScale(.09f, .09f);
	if (!lock4) {
		window.draw(spr4);
	}

	sf::Sprite spr5;
	spr5.setTexture(texture1);
	spr5.setPosition(437, 334);
	spr5.setScale(.09f, .09f);
	if (!lock5) {
		window.draw(spr5);
	}

	sf::Sprite spr6;
	spr6.setTexture(texture1);
	spr6.setPosition(709, 334);
	spr6.setScale(.09f, .09f);
	if (!lock6) {
		window.draw(spr6);
	}

	if (mouse.getMouse_x() >= 144 && mouse.getMouse_x() <= 272 &&
		mouse.getMouse_y() >= 132 && mouse.getMouse_y() <= 204) {
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			level = 1;
			inLevel = true;
		}
	}
	else if (mouse.getMouse_x() >= 416 && mouse.getMouse_x() <= 544 &&
		mouse.getMouse_y() >= 132 && mouse.getMouse_y() <= 204 &&
		lock2 == true) {
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			level = 2;
			inLevel = true;
		}
	}
	else if (mouse.getMouse_x() >= 688 && mouse.getMouse_x() <= 816 &&
		mouse.getMouse_y() >= 132 && mouse.getMouse_y() <= 204 &&
		lock3 == true) {
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			level = 3;
			inLevel = true;
		}
	}
	else if (mouse.getMouse_x() >= 144 && mouse.getMouse_x() <= 272 &&
		mouse.getMouse_y() >= 336 && mouse.getMouse_y() <= 408 &&
		lock4 == true) {
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			level = 4;
			inLevel = true;
		}
	}
	else if (mouse.getMouse_x() >= 416 && mouse.getMouse_x() <= 544 &&
		mouse.getMouse_y() >= 336 && mouse.getMouse_y() <= 408 &&
		lock5 == true) {
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			level = 5;
			inLevel = true;
		}
	}
	else if (mouse.getMouse_x() >= 688 && mouse.getMouse_x() <= 816 &&
		mouse.getMouse_y() >= 336 && mouse.getMouse_y() <= 408 &&
		lock6 == true) {
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			level = 6;
			inLevel = true;
		}
	}
}

void start_screen(Mouse& mouse) {
	window.clear(sf::Color::Green);
	sf::Font font1;
	sf::Text text1;
	if (!font1.loadFromFile("fonts/Golden Sands DEMO VERSION.ttf")) {
		std::cerr << "Hata olusdu!";
	}
	text1.setFont(font1);
	text1.setString("Golf Game");
	text1.setCharacterSize(50);
	text1.setFillColor(sf::Color::Red);
	text1.setStyle(sf::Text::Bold);
	text1.setPosition(350, 100);
	window.draw(text1);

	Barrier box(70, 70, 420, 400, 0, 0);
	box.renderBarrier(window);

	sf::VertexArray triangle(sf::Triangles, 3);
	triangle[0].position = sf::Vector2f(440, 410);
	triangle[1].position = sf::Vector2f(470, 440);
	triangle[2].position = sf::Vector2f(440, 460);

	triangle[0].color = sf::Color::Magenta;
	triangle[1].color = sf::Color::Magenta;
	triangle[2].color = sf::Color::Magenta;
	window.draw(triangle);
	if (mouse.getMouse_x() >= box.getRect_x() && mouse.getMouse_x() <= box.getRect_x() + box.getWidth() &&
		mouse.getMouse_y() >= box.getRect_y() && mouse.getMouse_y() <= box.getRect_y() + box.getHeight()) {
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			levelscreen = true;
		}
	}
}

void game_over_screen() {
	window.clear(sf::Color::White);

	sf::Font font_end;
	if (!font_end.loadFromFile("fonts/Dee-Quickest Sans.otf")) {
		std::cerr << "Hata olustu!";
	}
	sf::Text text_end;
	text_end.setFont(font_end);
	text_end.setCharacterSize(45);
	text_end.setFillColor(sf::Color::Black);
	text_end.setStyle(sf::Text::Bold);
	text_end.setPosition(400, 250);
	text_end.setString("Game Over");
	window.draw(text_end);

	endClock.restart();
}

void win_screen() {
	window.clear(sf::Color::Black);
	sf::Font font;
	font.loadFromFile("fonts/Dee-Quickest Sans.otf");
	sf::Text text;
	text.setCharacterSize(40);
	text.setFillColor(sf::Color::White);
	text.setFont(font);
	text.setStyle(sf::Text::Bold);
	text.setPosition(350, 240);
	text.setString("Congrates");
	window.draw(text);
}

void level1(Mouse &mouse,float dt) {
	window.clear(sf::Color::Green);

	//update
	ball1.update(dt);
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		++count;
	}

	//collision check
	ball_movement(mouse, ball1);
	arena_check(ball1);
	if (ballInHole(ball1, hole1)) {
		showWin1 = true;
		winClock.restart();
	}
	//render
	displayCount(count);
	ball1.render(window);
	hole1.render_hole(window);
}

void level2(Mouse& mouse, float dt) {
	window.clear(sf::Color::Green);

	//update
	ball2.update(dt);
	bar2.update(dt);
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		++count;
	}

	//collision check
	ball_movement(mouse, ball2);
	arena_check(ball2);
	ball_and_Bar(ball2, bar2);
	if (ballInHole(ball2, hole2)) {
		showWin2 = true;
		winClock.restart();
	}
	//render
	displayCount(count);
	ball2.render(window);
	hole2.render_hole(window);
	bar2.renderBarrier(window);
}

void level3(Mouse& mouse, float dt) {
	window.clear(sf::Color::Green);

	//update
	ball3.update(dt);
	ball_movement(mouse, ball3);
	bar3.update(dt);
	bar3_1.update(dt);
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		++count;
	}

	//collision check
	arena_check(ball3);
	ball_and_Bar(ball3, bar3);
	ball_and_Bar(ball3, bar3_1);
	if (ballInHole(ball3, hole3)) {
		showWin3 = true;
		winClock.restart();
	}
	//render
	displayCount(count);
	ball3.render(window);
	hole3.render_hole(window);
	bar3.renderBarrier(window);
	bar3_1.renderBarrier(window);
}

void level4(Mouse& mouse, float dt) {
	window.clear(sf::Color::Green);
	//update
	ball4.update(dt);
	ball_movement(mouse, ball4);
	bar4.update(dt);
	bar4_1.update(dt);
	bar4_2.update(dt);
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		++count;
	}

	//collision check
	arena_check(ball4);
	ball_and_Bar(ball4, bar4);
	ball_and_Bar(ball4, bar4_1);
	ball_and_Bar(ball4, bar4_2);
	if (ballInHole(ball4, hole4)) {
		showWin4 = true;
		winClock.restart();
	}

	//render
	displayCount(count);
	ball4.render(window);
	hole4.render_hole(window);
	bar4.renderBarrier(window);
	bar4_1.renderBarrier(window);
	bar4_2.renderBarrier(window);
}

void level5(Mouse& mouse, float dt) {
	window.clear(sf::Color::Green);
	
	//update
	ball5.update(dt);
	ball_movement(mouse, ball5);
	bar5.update(dt);
	bar5_1.update(dt);
	bar5_2.update(dt);
	bar5_3.update(dt);
	if (ballInHole(ball5, hole5)) {
		++count;
	}

	//collision check
	arena_check(ball5);
	ball_and_Bar(ball5, bar5);
	ball_and_Bar(ball5, bar5_1);
	ball_and_Bar(ball5, bar5_2);
	ball_and_Bar(ball5, bar5_3);
	if (ballInHole(ball5, hole5)) {
		showWin5 = true;
		winClock.restart();
	}

	//render
	displayCount(count);
	ball5.render(window);
	hole5.render_hole(window);
	bar5.renderBarrier(window);
	bar5_1.renderBarrier(window);
	bar5_2.renderBarrier(window);
	bar5_3.renderBarrier(window);
}

void level6(Mouse& mouse, float dt) {
	window.clear(sf::Color::Green);

	//update
	ball6.update(dt);
	ball_movement(mouse, ball6);
	bar6.update(dt);
	bar6_1.update(dt);
	bar6_2.update(dt);
	bar6_3.update(dt);
	bar6_4.update(dt);
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		++count;
	}

	//collision check
	arena_check(ball6);
	ball_and_Bar(ball6, bar6);
	ball_and_Bar(ball6, bar6_1);
	ball_and_Bar(ball6, bar6_2);
	ball_and_Bar(ball6, bar6_3);
	ball_and_Bar(ball6, bar6_4);
	if (ballInHole(ball6, hole6)) {
		showWin6 = true;
		winClock.restart();
	}

	//render
	displayCount(count);
	ball6.render(window);
	hole6.render_hole(window);
	bar6.renderBarrier(window);
	bar6_1.renderBarrier(window);
	bar6_2.renderBarrier(window);
	bar6_3.renderBarrier(window);
	bar6_4.renderBarrier(window);
}

int main() {
	float delta_time = deltaTime.restart().asSeconds();
	window.setVerticalSyncEnabled(true);

	while (window.isOpen()) {
		delta_time = deltaTime.restart().asSeconds();
		if (window.pollEvent(ev)) {
			if (ev.type == ev.Closed) {
				window.close();
			}
		}
		if (!game_over) {
			if (showWin1) {
				win_screen();
				if (winClock.getElapsedTime().asSeconds() >= 5.f) {
					showWin1 = false;
					inLevel = false;
					inLevel = false;
					lock2 = true;
					level = 0;
					count = 0;
				}
			}
			else if (showWin2) {
				win_screen();
				if (winClock.getElapsedTime().asSeconds() >= 5.f) {
					showWin2 = false;
					inLevel = false;
					levelscreen = false;
					lock3 = true;
					level = 0;
					count = 0;
				}
			}
			else if (showWin3) {
				win_screen();
				if (winClock.getElapsedTime().asSeconds() >= 5.f) {
					showWin3 = false;
					inLevel = false;
					levelscreen = false;
					lock4 = true;
					level = 0;
					count = 0;
				}
			}
			else if (showWin4) {
				win_screen();
				if (winClock.getElapsedTime().asSeconds() >= 5.f) {
					showWin4 = false;
					inLevel = false;
					levelscreen = false;
					lock5 = true;
					level = 0;
					count = 0;
				}
			}
			else if (showWin5) {
				win_screen();
				if (winClock.getElapsedTime().asSeconds() >= 5.f) {
					showWin5 = false;
					inLevel = false;
					levelscreen = false;
					lock6 = true;
					level = 0;
					count = 0;
				}
			}
			else if (showWin6) {
				win_screen();
				if (winClock.getElapsedTime().asSeconds() >= 5.f) {
					showWin6 = false;
					inLevel = false;
					levelscreen = false;
					level = 0;
					count = 0;
					game_over = true;
				}
			}
			else if (inLevel) {
				if (level == 1) {
					level1(mouse, delta_time);
				}
				else if (level == 2) {
					level2(mouse, delta_time);
				}
				else if (level == 3) {
					level3(mouse, delta_time);
				}
				else if (level == 4) {
					level4(mouse, delta_time);
				}
				else if (level == 5) {
					level5(mouse, delta_time);
				}
				else if (level == 6) {
					level6(mouse, delta_time);
				}
			}
			else {
				if (levelscreen) {
					level_screen(mouse);
				}
				else {
					start_screen(mouse);
				}
			}
		}
		else {
			game_over_screen();
			if (endClock.getElapsedTime().asSeconds() >= 5.f) {
				window.close();
			}
		}
		
		window.display();
	}
	return 0;
}
