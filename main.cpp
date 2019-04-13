#include <cstring>
#include <string>
#include <vector>
#include <iostream>

struct pointer {
    double x;
    double y;
};

struct figure_triangle {
    pointer vertex_first;
    pointer vertex_second;
    pointer vertex_third;
};

struct figure_circle {
    pointer vertex;
    double radius;
};

void skip_space(char* str, std::size_t &i)
{
    while (str[i] == ' ') {
        i++;
    }
}

void check_name_figure(char* str, std::size_t &i, std::size_t &begin_word, std::size_t &end_word)
{
    if (isalpha(str[i])) {
		begin_word = i;
	}
    while (isalpha(str[i])) {
		i++;
	}
	end_word = i - 1;
}

/*bool compare_string_circle(char* str, char* f)
{
	int size = 6;
	for (std::size_t i = 0; i < size)
}*/

int name_figure(char* str, std::size_t begin_word, std::size_t end_word)
{
    const char f1[] = {"circle"};
    const char f2[] = {"triangle"};
    char f0[100] = {};
    for (std::size_t i = begin_word, j = 0; i <= end_word; i++, j++) {
        f0[j] = str[i];
    }
    if (strcmp(f0, f1) == 0) {
        return 1;
    } else if (strcmp(f0, f2) == 0) {
        return 2;
    } else {
        return -1;
    }
}
// double strtod(const char *nptr, char **endptr);// symbol to double
// int strcmp(const char *s1, const char *s2);

double perimetr_circle(figure_circle circle, const double PI)
{
    return (2 * PI * circle.radius);
}

double square_circle(figure_circle circle, const double PI)
{
    return (PI * circle.radius * circle.radius);
}


int main()
{
    const double PI = 3.1415926535;
    //figure_triangle triangle;
    figure_circle circle;

    char str[100];
    std::cin.getline(str, 100);
    std::size_t i = 0;
	std::size_t begin_word, end_word;
    skip_space(str, i);
	check_name_figure(str, i, begin_word, end_word);
    int figure = name_figure(str, begin_word, end_word); //1 - circle, 2 - triangle
	skip_space(str, i);
    if (figure == 1) {
        if (str[i] == '(') {
            i++;
            char *EndPtr;
            skip_space(str, i);
            char coordinate_x[10] = {};
            for (std::size_t j = 0; str[i] == ' '; i++, j++) {
                coordinate_x[j] = str[i];
            }
            circle.vertex.x = std::strtod(coordinate_x, &EndPtr);
            skip_space(str, i);
            char coordinate_y[10] = {};
            for (std::size_t j = 0; str[i] == ' '; i++, j++) {
                coordinate_y[j] = str[i];
            }
            circle.vertex.y = std::strtod(coordinate_y, &EndPtr);
			i++;
            if (str[i] == ',') {
                i++;
                skip_space(str, i);
                char radius_circle[] = "";
                for (std::size_t j = 0; str[i] == ' '; i++, j++) {
                    radius_circle[j] = str[i];
                }
                circle.radius = std::strtod(radius_circle, &EndPtr);
                skip_space(str, i);
                if (str[i] == ')') {
                    i++;
                    std::cout << "Perimetr circle: " << perimetr_circle(circle, PI) << std::endl;
                    std::cout << "Square circle: " << square_circle(circle, PI) << std::endl;
                } else {
                    std::cout << "missing )" << std::endl;
                }
            }
        } else {
            std::cout << "missing (" << std::endl;
        }
    }/* else if (figure == 2) {
        if ((str[i] == '(') && (str[i + 1] == '(')) {
            i = i + 2;
            skip_space(str, i);
        } else {
            std::cout << "missing ((" << std::endl;
        }
    }*/
	else {
		std::cout << "Error name figure" << std::endl;
	}
    return 0;
}
