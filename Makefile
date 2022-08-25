
include Config
.PONHY: clean install uninstall

Target=chameleon-admin
ALL=app chameleon-admin cmds conf db http models template urls utils views

$(Target):libchameleon.a
	@echo Building chameleon-admin...
	$(CXX) src/main.cpp -Iinclude -w -Lbin -lchameleon -lsqlite3 -o bin/chameleon-admin
libchameleon.a:app
	@echo Building libchameleon.a
	ar rcsv bin/libchameleon.a temp/*.o

app:
	@for i in $(ALL);do echo "Build ($$i)"; $(MAKE) -C src/$$i; done;

install:uninstall
	@echo "	cp headers --> /usr/include/chameleon"
	@cp include/chameleon /usr/include/chameleon -rf
	@echo "	cp chameleon-admin --> /usr/bin/chameleon-admin"
	@cp bin/chameleon-admin /usr/bin/chameleon-admin
	@echo "	cp libchameleon.a --> /lib/libchameleon.a"
	@cp bin/libchameleon.a /lib/libchameleon.a 
	@echo "	Ok"

uninstall:
	rm -rf /usr/include/chameleon
	rm /lib/libchameleon.a
	rm /usr/bin/chameleon-admin

clean:
	@echo Cleaning...
	@$(RM) temp/*
	@$(RM) bin/*
	@echo Ok