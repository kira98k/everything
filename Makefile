
cpp:
	@g++ template.cpp -o template -D DEBUG
	@./template < inp.txt
	@rm template

rust:
	@rustc template.rs
	@./template < inp.txt
	@rm template

python:
	@python3 template.py < inp.txt