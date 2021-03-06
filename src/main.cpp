#include "calculation.h"

void skip_space(char* str, std::size_t& i)
{
    while (str[i] == ' ') {
        i++;
    }
}

void check_name_figure(
        char* str,
        std::size_t& i,
        std::size_t& begin_word,
        std::size_t& end_word)
{
    if (isalpha(str[i])) {
        begin_word = i;
    }
    while (isalpha(str[i])) {
        i++;
    }
    end_word = i - 1;
}

int name_figure(char* str, std::size_t begin_word, std::size_t end_word)
{
    const char f1[] = {"circle"};
    char f0[100] = {};
    for (std::size_t i = begin_word, j = 0; i <= end_word; i++, j++) {
        f0[j] = str[i];
    }
    if (strcmp(f0, f1) == 0) {
        return 1;
    } else {
        return -1;
    }
}

int main()
{
    figure_circle circle;

    char str[100];
    std::cin.getline(str, 100);
    std::size_t size = std::strlen(str);
    if (size == 0) {
        std::cout << "Empty str" << std::endl;
        return 0;
    }

    std::size_t i = 0;
    std::size_t begin_word, end_word;
    skip_space(str, i);

    check_name_figure(str, i, begin_word, end_word);
    int figure = name_figure(str, begin_word, end_word); // 1 - circle

    skip_space(str, i);
    if (figure != 1) {
        std::cout << "Error name figure" << std::endl;
        return 0;
    }
    if (str[i] != '(') {
        std::cout << "missing (" << std::endl;
        return 0;
    }
    i++;
    char* EndPtr;
    skip_space(str, i);
    char coordinate_x[100] = {};
    for (std::size_t j = 0; str[i] != ' '; i++, j++) {
        coordinate_x[j] = str[i];
    }
    circle.vertex.x = strtod(coordinate_x, &EndPtr);
    skip_space(str, i);
    char coordinate_y[100] = {};
    for (std::size_t j = 0; ((str[i] != ' ') && (str[i] != ',')); i++, j++) {
        coordinate_y[j] = str[i];
    }
    // circle(0 0, 1.5)
    circle.vertex.y = strtod(coordinate_y, &EndPtr);
    skip_space(str, i);
    if (str[i] != ',') {
        std::cout << "missing ," << std::endl;
        return 0;
    }
    i++;
    skip_space(str, i);
    char radius_circle[100] = {};
    for (std::size_t j = 0; ((str[i] != ' ') && (str[i] != ')')); i++, j++) {
        radius_circle[j] = str[i];
    }
    circle.radius = strtod(radius_circle, &EndPtr);
    std::cout << circle.radius << std::endl;
    skip_space(str, i);
    if (str[i] != ')') {
        std::cout << "missing )" << std::endl;
        return 0;
    }
    i++;
    skip_space(str, i);
    if (i != size) {
        std::cout << "There are extraneous characters after )" << std::endl;
        return 0;
    }
    std::cout << "Perimetr circle: " << perimetr_circle(circle, PI)
              << std::endl;
    std::cout << "Square circle: " << square_circle(circle, PI) << std::endl;
    return 0;
}
