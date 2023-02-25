#include <iostream> 
//Внесіть виправлення в текст програми таким чином, щоб при спробі виводу об'єкта було видно текст, який в ньому є

class SomeString {
public:
	SomeString(int a) { // виділяємо рядок розміром a
		m_string.resize(a);
	}

	template <typename T>
	SomeString(T string) {
		// виділяємо рядок для зберігання значення типу string
		m_string = string;
	}

	friend std::ostream& operator<<(std::ostream& out, const SomeString& s);

private:
	std::string m_string;
};

std::ostream& operator<<(std::ostream& out, const SomeString& s) {
	// static_cast<std::string>() - useless
	out << static_cast<std::string>(s.m_string); 
	return out;
}

int main() {
	SomeString mystring = 'a'; // виконується копіююча ініціалізація
	std::cout << mystring;

	return 0;
}
