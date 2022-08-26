
include Config
.PONHY: clean install uninstall

Target=chameleon-admin
ALL=app chameleon-admin cmds conf db http models template urls utils views
TOOLS=hiberlite
INCLUDE=-Iinclude -Itools/hiberlite/include
LIBPATH=-Lbin -Ltools/hiberlite/bin
LIB=-lchameleon -lhiberlite -lsqlite3 -lpthread -ldl

$(Target):libchameleon.a
	@echo Building chameleon-admin...
	$(CXX) src/main.cpp $(INCLUDE) -w $(LIBPATH) $(LIB) -o bin/chameleon-admin $(FLAG)
libchameleon.a:tool app
	@echo Building libchameleon.a
	ar rcsv bin/libchameleon.a temp/*.o

app:
	@for i in $(ALL);do echo "	Build ($$i)"; $(MAKE) -C src/$$i; done;
tool:
	@for i in $(TOOLS);do echo "	Build ($$i)"; $(MAKE) -C tools/$$i/src; done;

install:uninstall tools_install
	@echo "	Install chameleon"
	@cp include/chameleon /usr/include/chameleon -rf
	@cp bin/chameleon-admin /usr/bin/chameleon-admin
	@cp bin/libchameleon.a /lib/libchameleon.a 
	@echo "	Ok"

uninstall:tools_uninstall 
	@echo "	Remove chameleon"
	rm -rf /usr/include/chameleon
	rm -f /lib/libchameleon.a
	rm -f /usr/bin/chameleon-admin

tools_install:
	@for i in $(TOOLS);do echo "	Install ($$i)"; $(MAKE) -C tools/$$i/src install; done;

tools_uninstall:
	@for i in $(TOOLS);do echo "	uninstall ($$i)"; $(MAKE) -C tools/$$i/src uninstall; done;
clean:
	@echo Cleaning...
	@for i in $(TOOLS);do echo "	Clean ($$i)"; $(MAKE) -C tools/$$i/src clean; done;
	@$(RM) temp/*
	@$(RM) bin/*
	@echo Ok