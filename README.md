# Violet_Sources
This is the repository of Pokémon Violet. It can be used to build the project from source instead of applying a patch or to get an insight into how the features work. This README describes the repository rather than the project itself. Visit the project [website](http://wodkarhr.github.io/Violet_Sources/) for information about the game.

## Requirements
The build process of this repository requires you to have installed:

### Tools
- [devkitPro](https://sourceforge.net/projects/devkitpro/)
- [armips](https://github.com/Kingcom/armips)
- [python 3](https://www.python.org/)
- [wav2wagb](https://github.com/ipatix/wav2agb)
- [mid2agb](https://hackromtools.altervista.org/sappy-mid2agb/)
- [SoundFontRipper]

### Python
This project provides a `Pipfile` for automatically installing all `pip`-dependencies.  
Either invoke `pipenv install --system` in order to install the dependencies system-wide, or `pipenv install` in order to create a new virtual environment with the dependencies installed. Please refer to [the docs](https://docs.pipenv.org/) for further information.

### Resources
- A german firered rom (download is illegal!) located at `./base/bprd.gba`
- `psg_data.raw` from [SoundFontRipper] located at `./psg_data.raw`
- `goldensun_synth.raw` from [SoundFontRipper] located at `./goldensun_synth.raw`

## Configuration
Adjust the commands in the `makefile` to execute the binaries above.

## Building

Simply run the makefile:
```
$ make all
```

## Adding and Testing Ingame-Features
There is a map called `map_4_3_debug` where you can place scripts or npcs for entering experimental scenarios.  
You can get to the map by loading the cheat file located at `Violet/sav/Debug Mode.clt` and holding <kbd>L</kbd> + <kbd>R</kbd> and <kbd>A</kbd> while examining the console in the player's room.

## ToDo
  - Make use of [Midi2Agb](https://github.com/ipatix/midi2agb) instead of `mid2agb`.

<!--- References -->
[SoundFontRipper]: https://github.com/WodkaRHR/gba-mus-ripper
