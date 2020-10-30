FROM gcc
CMD [ "/usr/local/bin/violet-entrypoint" ]

RUN apt-get update --fix-missing
RUN DEBIAN_FRONTEND=nointeractive apt-get install apt-utils -y
RUN apt-get install -y locales
RUN localedef -i en_US -c -f UTF-8 -A /usr/share/locale/locale.alias en_US.UTF-8

ENV LANG en_US.utf8
ENV DEBIAN_FRONTEND nointeractive
ENV PIPENV_VENV_IN_PROJECT true

RUN apt-get update --fix-missing
RUN apt-get install -y \
        libgl1-mesa-dev \
        gcc-arm-none-eabi \
        cmake \
        bc \
        python3-pip
RUN pip3 install --upgrade pip
RUN pip3 install pipenv

RUN \
        wget https://github.com/devkitPro/pacman/releases/download/v1.0.2/devkitpro-pacman.amd64.deb -O pacman.deb; \
        dpkg -i pacman.deb; \
        dkp-pacman -S --noconfirm gba-dev; \
        rm pacman.deb;
RUN \
        wget https://github.com/gohugoio/hugo/releases/download/v0.76.5/hugo_0.76.5_Linux-64bit.deb -O hugo.deb; \
        dpkg -i hugo.deb; \
        rm hugo.deb;

ENV DEVKITPRO /opt/devkitpro
ENV DEVKITARM ${DEVKITPRO}/devkitARM
ENV DEVKITPPC ${DEVKITPRO}/devkitPPC
ENV PATH ${DEVKITPRO}/tools/bin:$PATH

RUN mkdir -p /etc/violet
WORKDIR /etc/violet
RUN \
        cd /etc/violet; \
        \
        git clone https://github.com/ipatix/wav2agb; \
        directory=$(pwd); \
        cd wav2agb; \
        git checkout 3acb19c8d11d017d39d77a87fa8630d07945a6c4; \
        make; \
        chmod 744 wav2agb; \
        install -t /usr/local/bin ./wav2agb; \
        cd $directory; \
        unset directory;
RUN \
        git clone https://github.com/pret/pokefirered.git; \
        directory=$(pwd); \
        cd pokefirered/tools/mid2agb; \
        git checkout 7b8c935926eec33651e0e265fa49f2f99fce918a; \
        make; \
        chmod 744 mid2agb; \
        install -t /usr/local/bin ./mid2agb; \
        cd $directory; \
        unset directory;
RUN \
        git clone https://github.com/Kingcom/armips.git; \
        directory=$(pwd); \
        cd armips; \
        git checkout v0.11.0; \
        cmake .; \
        make; \
        chmod 744 armips; \
        install -t /usr/local/bin ./armips; \
        cd $directory; \
        unset directory;
RUN \
        git clone https://github.com/WodkaRHR/gba-mus-ripper.git /etc/violet/gba-mus-ripper; \
        directory=$(pwd); \
        cd gba-mus-ripper; \
        git checkout a1c8ed924420fa7f2a311f61a88915aed8018bf9; \
        make; \
        chmod 744 ./*; \
        install -t /usr/local/bin ./out/*; \
        cd $directory; \
        unset directory;

WORKDIR /usr/local/violet
COPY .docker/buildbot-entrypoint.sh /usr/local/bin/violet-entrypoint