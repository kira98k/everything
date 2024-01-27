
all:
	g++ template.cpp -o template -D DEBUG
	./template < inp.txt
	rm template