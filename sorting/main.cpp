#include <SFML/Graphics.hpp>

#include <iostream>
#include <vector>
#include <array>
#include <random>
#include <ranges>
#include <algorithm>
#include <thread>         
#include <chrono>

#include "Merge.hpp"

// Initialise the window
sf::RenderWindow wnd(sf::VideoMode(960, 600), "Sorting");
int width = sf::VideoMode::getDesktopMode().width;
int height = sf::VideoMode::getDesktopMode().height;

bool sorted = false;
std::vector<int> values;

void bars(int index) {

	// Start drawing
	wnd.clear(sf::Color::Black);

	// Draw bars for each value
	for (int i = 0; i < sizeof(values); i++) {
		sf::RectangleShape bar(sf::Vector2f(10, values[i]));
		bar.setPosition(i * 12, height - values[i]);
		bar.setFillColor(((i = index) || sorted) ? sf::Color::Green : sf::Color::White);
		wnd.draw(bar);
	}

	// end current frame
	wnd.display();
}

void insertionSort() {
	unsigned int millisecond = 1000000;
	std::this_thread::sleep_for(std::chrono::milliseconds(millisecond * 5));
	int i, key, j;
	for (i = 0; i < width / 12; i++) {
		key = values[i];
		j = i - 1;

		while (j >= 0 && values[j] > key) {
			values[j + 1] = values[j];
			j = j - 1;
			bars(j);
		}
		values[j + 1] = key;
	}

	sorted = true;

	bars(i);

}

int main() {
	// Random Number Generator
	std::random_device rd;
	std::uniform_int_distribution<int> d(1, height - 50);

	// Fill Vector With Random Numbers
	for (int i = 0; i < width / 12; i++) {
		values.push_back(d(rd));
	}
	// Make sure the window is running
	while (wnd.isOpen()) {
		sf::Event ev;
		while (wnd.pollEvent(ev)) {
			if (ev.type == sf::Event::Closed) {
				wnd.close();
			}
		}
		if (!sorted) {
			bars(0);
			insertionSort();
		}
	}
	return 0;
}

