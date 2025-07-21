WORKDIR = .

HTTP_CLIENT=$(WORKDIR)/example/httpclient
HTTP_SERVER=$(WORKDIR)/example/httpserver
TCP_CLIENT=$(WORKDIR)/example/tcpclient
TCP_SERVER=$(WORKDIR)/example/tcpserver
WS_CLIENT=$(WORKDIR)/example/wsclient
WS_SERVER=$(WORKDIR)/example/wsserver

default: all

all: httpclient httpserver tcpclient tcpserver wsclient wsserver

httpclient:
	@go build -o $(HTTP_CLIENT)/httpclient $(HTTP_CLIENT)/*.go >/dev/null;

httpserver:
	@go build -o $(HTTP_SERVER)/httpserver $(HTTP_SERVER)/*.go >/dev/null;

tcpclient:
	@go build -o $(TCP_CLIENT)/tcpclient $(TCP_CLIENT)/*.go >/dev/null;

tcpserver:
	@go build -o $(TCP_SERVER)/tcpserver $(TCP_SERVER)/*.go >/dev/null;

wsclient:
	@go build -o $(WS_CLIENT)/wsclient $(WS_CLIENT)/*.go >/dev/null;

wsserver:
	@go build -o $(WS_SERVER)/wsserver $(WS_SERVER)/*.go >/dev/null;

.PHONY:clean

clean:
	rm $(HTTP_CLIENT)/httpclient $(HTTP_SERVER)/httpserver $(TCP_CLIENT)/tcpclient $(TCP_SERVER)/tcpserver \
	$(WS_CLIENT)/wsclient $(WS_SERVER)/wsserver