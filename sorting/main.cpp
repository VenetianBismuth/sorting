#include <SFML/Graphics.hpp>

#include <iostream>
#include <vector>
#include <array>
#include <random>
#include <ranges>
#include <algorithm>
#include <thread>         
#include <chrono>

// Initialise the window
sf::RenderWindow wnd(sf::VideoMode(960, 600), "Sorting Visualiser");
int width = sf::VideoMode::getDesktopMode().width;
int height = sf::VideoMode::getDesktopMode().height;

bool sorted = false;
std::vector<int> values;


void bars(int index) {

	// Start drawing
	wnd.clear(sf::Color::Black);

	// Draw bars for each value
	for (int i = 0; i < values.size(); i++) {
		sf::RectangleShape bar(sf::Vector2f(10, values[i]));
		bar.setPosition(i * 12, height - values[i]);
		bar.setFillColor(((i == index) || sorted) ? sf::Color::Green : sf::Color::White);
		wnd.draw(bar);
	}

	// End current frame
	wnd.display();
}

void recurs_merge(std::vector<int>& values, int l, int r) {
	
	// Base case
	if (l >= r) return;
	//
	const int m = (l + r) / 2;

	// Recursion
	recurs_merge(values, l, m); // The first half
	recurs_merge(values, m + 1, r); // The second half

	// Initialising sub vectors
	std::vector<int> arrL(m - l + 1);
	std::vector<int> arrR(r - m); 

	for (int i = 0; i <= m - l; i++) {
		arrL[i] = values[l + i];
	}
	for (int i = 0; i < r - m; i++) { //changed an = sign
		arrR[i] = values[m + 1 + i];
	}
	
	// Merging the sorted vectors into a temporary vector
	std::vector<int> temp(r - l + 1);
	std::merge(values.begin() + l, values.begin() + m + 1, values.begin() + m + 1, values.begin() + r + 1, temp.begin());
	
	std::copy(temp.begin(), temp.end(), values.begin() + l);
	

	// Výsualising the merging
	bars(l);
	std::this_thread::sleep_for(std::chrono::milliseconds(40));

}

void merge_sort(std::vector<int>& values) {
	recurs_merge(values, 0, values.size() - 1);
	sorted = true;
}

int main() {
	// Random Number Generator
	std::random_device rd;
	std::uniform_int_distribution<int> d(50, height - 20);

	// Fill Vector With Random Numbers
	for (int i = 0; i < width / 12; i++) {
		values.push_back(d(rd));
	}
	// Make sure the window is running
	while (wnd.isOpen()) {
		sf::Event ev;
		while (wnd.pollEvent(ev)) {
			// Setting up keys: ESC: Quit, SPACE: Run the program (for now...)
			if (ev.type == sf::Event::Closed) wnd.close();

			else if (ev.type == sf::Event::KeyPressed) {
				if (ev.key.code == sf::Keyboard::Escape) wnd.close();
			}
			else if (ev.key.code == sf::Keyboard::M && !sorted) {
				std::cout << "M Key Pressed! Sorting..." << std::endl;
				merge_sort(values);
			}
			if (!sorted) bars(0);
			else {
				std::cout << "Sorted!" << std::endl;
				std::this_thread::sleep_for(std::chrono::seconds(3));
				wnd.close();
			}
		}
		
	}
	return 0;
}



