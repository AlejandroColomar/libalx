FROM	centos:centos8
RUN	apt-get update							&& \
	apt-get upgrade --yes						&& \
	apt-get install -V \
			gcc \
			gcc-c++ \
			make \
			git \
			pkgconf-pkg-config \
			libbsd-devel \
			libcurl-devel \
			libgmp-devel \
			libgsl-devel \
			libncurses-devel \
			libopencv-devel \
			tesseract-devel \
			zbar-devel \
			deborphan \
			--yes						&& \
	apt-get autoremove --purge --yes				&& \
	apt-get purge $(deborphan) --yes				&& \
	apt-get autoclean						&& \
	apt-get clean

## centos8 doesn't have Opencv4, which is required by libalx-cv

##
## Use the container to build programs that depend on libalx
## (or to build libalx itself).
## These commands need to be called from the pparent directory where libalx
## and any other programs are.
##
# docker container run --user $(id -u):$(id -g) --tty --interactive --volume $PWD:$PWD --workdir $PWD --name code alejandrocolomar/debian:testing-code bash
# docker container start code
# docker container exec --user root --workdir $PWD code make install --directory libalx
# docker container exec --user root --tty --interactive --workdir $PWD code bash
# docker container attach code
