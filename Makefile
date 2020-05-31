CXXFLAGS = --std=c++17
GTKFLAGS = `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`

chess_game: main.o main_window.o piece.o pawn.o queen.o king.o rook.o knight.o bishop.o board.o player.o game.o
	$(CXX) $(CXXFLAGS) -o chess_game main.o main_window.o pawn.o piece.o queen.o king.o rook.o knight.o bishop.o board.o player.o game.o $(GTKFLAGS) -g

main.o : main.cpp *.h
	$(CXX) $(CXXFLAGS) -c main.cpp $(GTKFLAGS) -g

main_window.o : main_window.cpp *.h
	$(CXX) $(CXXFLAGS) -c main_window.cpp $(GTKFLAGS) -g

pawn.o : pawn.cpp *.h
	$(CXX) $(CXXFLAGS) -c pawn.cpp $(GTKFLAGS) -g

piece.o : piece.cpp *.h
	$(CXX) $(CXXFLAGS) -c piece.cpp $(GTKFLAGS) -g

queen.o : queen.cpp *.h
	$(CXX) $(CXXFLAGS) -c queen.cpp $(GTKFLAGS) -g

king.o : king.cpp *.h
	$(CXX) $(CXXFLAGS) -c king.cpp $(GTKFLAGS) -g

bishop.o : bishop.cpp *.h
	$(CXX) $(CXXFLAGS) -c bishop.cpp $(GTKFLAGS) -g

rook.o : rook.cpp *.h
	$(CXX) $(CXXFLAGS) -c rook.cpp $(GTKFLAGS) -g

knight.o : knight.cpp *.h
	$(CXX) $(CXXFLAGS) -c knight.cpp $(GTKFLAGS) -g

board.o : board.cpp *.h
	$(CXX) $(CXXFLAGS) -c board.cpp $(GTKFLAGS) -g

player.o : player.cpp *.h
	$(CXX) $(CXXFLAGS) -c player.cpp $(GTKFLAGS) -g

game.o : game.cpp *.h
	$(CXX) $(CXXFLAGS) -c game.cpp $(GTKFLAGS) -g


clean:
	-rm -f *.o *.gch *~ chess_game


	
