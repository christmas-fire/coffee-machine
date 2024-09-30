# Компилятор
CXX = g++

# Флаги компиляции
CXXFLAGS = -Wall -std=c++17 -I./headers # Добавляем -I./headers для указания директории с заголовочными файлами
  
# Директории
SRCDIR = src
BINDIR = bin
HEADERSDIR = headers

# Имя исполняемого файла
TARGET = $(BINDIR)/coffee_machine

# Заголовочные файлы
HEADERS = $(HEADERSDIR)/coffee_machine.h $(HEADERSDIR)/ingredients.h $(HEADERSDIR)/recipes.h

# Исходные файлы
SRC = $(SRCDIR)/coffee_machine.cpp $(SRCDIR)/ingredients.cpp $(SRCDIR)/main.cpp $(SRCDIR)/recipes.cpp

# Объектные файлы
OBJ = $(SRC:.cpp=.o)

# Правило для сборки всех файлов
all: $(TARGET)

# Правило для создания исполняемого файла
$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ)

# Правило для компиляции .cpp файлов в .o
%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Очистка всех сгенерированных файлов
clean:
	rm -f $(OBJ) $(TARGET)
	
# Запуск программы после сборки
run: $(TARGET)
	./$(TARGET)
