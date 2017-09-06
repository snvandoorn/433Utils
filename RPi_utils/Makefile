all: send codesend RFSniffer
<<<<<<< HEAD
#CXXFLAGS=-g3
=======
>>>>>>> e2682c360be511c4fd9877ca4350acb97bfb885b

send: RCSwitch.o send.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $+ -o $@ -lwiringPi
	
codesend: RCSwitch.o codesend.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $+ -o $@ -lwiringPi
	
RFSniffer: RCSwitch.o RFSniffer.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $+ -o $@ -lwiringPi
	

clean:
<<<<<<< HEAD
	$(RM) *.o send codesend servo RFSniffer
=======
	$(RM) *.o send codesend servo RFSniffer
>>>>>>> e2682c360be511c4fd9877ca4350acb97bfb885b
