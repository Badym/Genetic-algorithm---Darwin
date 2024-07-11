
#############################
# Generator plikow makefile #
# Krzysztof Siminski, 2022  #
#############################

# STALE:
kompilator=g++
standard=-std=c++20

optRelease=-O3
optDebug=

errors=-pedantic-errors

release=
debug=-g

#rownoleglosc=-fopenmp
rownoleglosc=

release_folder=_release
debug_folder=_debug

#############################

.PHONY : clean $(debug_folder) $(release_folder)

# opcje uruchomienia projektu:

release : $(release_folder) $(release_folder)/main
	./$(release_folder)/main
	./$(release_folder)/main -i input.txt -o output.txt -w 0.9 -r 0.9 -p 456 -k 8
	./$(release_folder)/main -i wej -o wyj -w 0.45 -r 0.67 -k 8 -p 456
#  niepoprawne
	./$(release_folder)/main -i wej -o wyj -w 0.45 -r 0.67 -q 8 -p 456
	./$(release_folder)/main -i wej -o wyj -w 0.45 -r 0.67 -k 8 
	./$(release_folder)/main -i wej -o wyj -w 0.45 -r 0.67 -k 8 -p 456 -i wejscie.txt
	./$(release_folder)/main -i wej -o wyj -w 0.45 -r 0.67 -p 456 -k 
	./$(release_folder)/main -i wej -o wyj -w 0.45 -r 0.67 -p 456 8  -k

debug : $(debug_folder) $(debug_folder)/main
	valgrind --leak-check=yes ./$(debug_folder)/main

# utworzenie folderow:

$(release_folder) : 
	mkdir -p $(release_folder)
$(debug_folder) : 
	mkdir -p $(debug_folder)

# kompilacja zrodel:

$(release_folder)/Dawrwin_inne_podejscie.o : Dawrwin_inne_podejscie.cpp
	$(kompilator) $(standard) $(release) $(optRelease) $(rownoleglosc) $(errors) -c -o $@ $^
$(debug_folder)/Dawrwin_inne_podejscie.o : Dawrwin_inne_podejscie.cpp
	$(kompilator) $(standard) $(debug) $(optyDebug) $(rownoleglosc) $(errors) -c -o $@ $^
$(release_folder)/funkcje.o : funkcje.cpp
	$(kompilator) $(standard) $(release) $(optRelease) $(rownoleglosc) $(errors) -c -o $@ $^
$(debug_folder)/funkcje.o : funkcje.cpp
	$(kompilator) $(standard) $(debug) $(optyDebug) $(rownoleglosc) $(errors) -c -o $@ $^

# linkowanie:

$(release_folder)/main : $(release_folder)/funkcje.o $(release_folder)/Dawrwin_inne_podejscie.o 
	$(kompilator) $(standard) $(release) $(optRelease) $(rownoleglosc) $(errors) -o $@ $^

$(debug_folder)/main : $(debug_folder)/funkcje.o $(debug_folder)/Dawrwin_inne_podejscie.o 
	$(kompilator) $(standard) $(debug) $(optDebug) $(rownoleglosc) $(errors) -o $@ $^

# usuniecie plikow skompilowanych:

clean : 
	if [ -d $(debug_folder)      ] ; then rm -r $(debug_folder)   ; fi
	if [ -d $(release_folder)    ] ; then rm -r $(release_folder) ; fi;


