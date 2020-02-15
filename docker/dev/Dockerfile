FROM	debian:testing
RUN	apt-get update							&& \
	apt-get upgrade --yes						&& \
	apt-get install -V \
			gcc \
			g++ \
			make \
			git \
			pkg-config \
			libbsd-dev \
			libcurl4-openssl-dev \
			libgmp3-dev \
			libgsl-dev \
			libncurses-dev \
			libopencv-dev \
			libtesseract-dev \
			libzbar-dev \
			deborphan \
			--yes						&& \
	apt-get autoremove --purge --yes				&& \
	apt-get purge $(deborphan) --yes				&& \
	apt-get autoclean						&& \
	apt-get clean

WORKDIR	/tmp
RUN		git clone https://github.com/alejandro-colomar/libalx.git	&& \
		make		-C libalx	-j 8				&& \
		make install	-C libalx					&& \
		rm -rf libalx


## Use this container to build programs that depend on libalx.
## These commands need to be called from the parent directory where the
## programs are.
# docker container run --user $(id -u):$(id -g) --tty --interactive --volume $PWD:$PWD --workdir $PWD --name libalx-dev alejandrocolomar/libalx:dev bash
# docker container start code
# docker container exec --user root --workdir $PWD code make install --directory <repository_dir>
# docker container exec --user root --tty --interactive --workdir $PWD code bash
# docker container attach code
