# Dat Pham
# CS 165 Project 10b

all:store

store: storeMain.o Store.o Customer.o Product.o
	g++ -g storeMain.o Store.o Customer.o Product.o -o store

storeMain.o: storeMain.cpp Store.hpp Customer.hpp Product.hpp
	g++ -c storeMain.cpp

Store.o: Store.cpp Store.hpp Customer.hpp
	g++ -c Store.cpp

Customer.o: Customer.cpp Customer.hpp Product.hpp
	g++ -c Customer.cpp

Product.o: Product.cpp Product.hpp
	g++ -c Product.cpp

clean:
	rm -f *.o
