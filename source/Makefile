#makefile for item_test

item_test: test_tools/test_tools.o Miscellaneous.o StorageEntities.o Storage.o GameObject.o LevelableObject.o Item.o item_test.o
	g++ test_tools/test_tools.o Miscellaneous.o StorageEntities.o Storage.o GameObject.o LevelableObject.o Item.o item_test.o -o item_test -std="c++11"

inventory_test: test_tools/test_tools.o Miscellaneous.o StorageEntities.o Storage.o GameObject.o LevelableObject.o Item.o Inventory.o inventory_test.o
	g++ test_tools/test_tools.o Miscellaneous.o StorageEntities.o Storage.o GameObject.o LevelableObject.o Item.o Inventory.o inventory_test.o -o inventory_test -std="c++11"

inventory_test.o: inventory_test.cpp
	g++ -c inventory_test.cpp -o inventory_test.o -std="c++11"

item_test.o: item_test.cpp
	g++ -c item_test.cpp -o item_test.o -std="c++11"

Inventory.o: Inventory.cpp
	g++ -c Inventory.cpp -o Inventory.o -std="c++11"

Item.o: Item.cpp
	g++ -c Item.cpp -o Item.o -std="c++11"

LevelableObject.o: LevelableObject.cpp
	g++ -c LevelableObject.cpp -o LevelableObject.o -std="c++11"

GameObject.o: GameObject.cpp
	g++ -c GameObject.cpp -o GameObject.o -std="c++11"

Miscellaneous.o: Miscellaneous.cpp
	g++ -c Miscellaneous.cpp -o Miscellaneous.o -std="c++11"

StorageEntities.o: StorageEntities.cpp
	g++ -c StorageEntities.cpp -o StorageEntities.o -std="c++11"

Storage.o: Storage.cpp
	g++ -c Storage.cpp -o Storage.o -std="c++11"

test_tools/test_tools.o: test_tools/test_tools.cpp
	g++ -c test_tools/test_tools.cpp -o test_tools/test_tools.o -std="c++11"

clean:
	rm -f *.o
