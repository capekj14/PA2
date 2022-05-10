CXX = g++
CXX_FLAGS = -g -Wall -pedantic -std=c++17
BIN = capekj14

compile: $(BIN)

dec: src/*.h README.md
	doxygen Doxyfile

run: compile
	./$(BIN)

$(BIN): build/Application.o build/Common.o build/LeaderBoard.o build/Page.o build/Player.o build/Question.o build/QuestionFreeAnswer.o build/QuestionMultiChoice.o build/QuestionSingleChoice.o build/QuestionYesNo.o build/Quiz.o build/QuizMaker.o build/main.o
	$(CXX) $^ -o $@ -lstdc++fs

build/%.o: src/%.cpp
	mkdir -p build
	$(CXX) $(CXX_FLAGS) $< -c -o $@

clean:
	rm -rf $(BIN) build/ 2>/dev/null

build/Application.o: src/Application.cpp src/Application.h src/Quiz.h src/Page.h src/Question.h src/QuestionType.h src/QuizMaker.h src/Common.h src/QuestionFreeAnswer.h src/QuestionMultiChoice.h src/QuestionSingleChoice.h src/QuestionYesNo.h src/Player.h src/LeaderBoard.h
build/Common.o: src/Common.cpp src/Common.h
build/LeaderBoard.o: src/LeaderBoard.cpp src/LeaderBoard.h src/Player.h src/Common.h
build/Page.o: src/Page.cpp src/Page.h src/Question.h src/QuestionType.h src/QuizMaker.h src/Common.h src/QuestionFreeAnswer.h src/QuestionMultiChoice.h src/QuestionSingleChoice.h src/QuestionYesNo.h
build/Player.o: src/Player.cpp src/Player.h src/Common.h
build/Question.o: src/Question.cpp src/Question.h src/QuestionType.h src/QuizMaker.h src/Common.h
build/QuestionFreeAnswer.o: src/QuestionFreeAnswer.cpp src/QuestionFreeAnswer.h src/Question.h src/QuestionType.h src/QuizMaker.h src/Common.h
build/QuestionMultiChoice.o: src/QuestionMultiChoice.cpp src/QuestionMultiChoice.h src/Question.h src/QuestionType.h src/QuizMaker.h src/Common.h
build/QuestionSingleChoice.o: src/QuestionSingleChoice.cpp src/QuestionSingleChoice.h src/Question.h src/QuestionType.h src/QuizMaker.h src/Common.h
build/QuestionYesNo.o: src/QuestionYesNo.cpp src/QuestionYesNo.h src/Question.h src/QuestionType.h src/QuizMaker.h src/Common.h
build/Quiz.o: src/Quiz.cpp src/Quiz.h src/Page.h src/Question.h src/QuestionType.h src/QuizMaker.h src/Common.h src/QuestionFreeAnswer.h src/QuestionMultiChoice.h src/QuestionSingleChoice.h src/QuestionYesNo.h src/Player.h src/LeaderBoard.h
build/QuizMaker.o: src/QuizMaker.cpp src/QuizMaker.h src/QuestionType.h src/Common.h
build/main.o: src/main.cpp src/Application.h src/Quiz.h src/Page.h src/Question.h src/QuestionType.h src/QuizMaker.h src/Common.h src/QuestionFreeAnswer.h src/QuestionMultiChoice.h src/QuestionSingleChoice.h src/QuestionYesNo.h src/Player.h src/LeaderBoard.h
