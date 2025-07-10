export LANG=en_US.UTF-8

clear
echo -e "░██████╗░███████╗███╗░░██╗███████╗░██████╗██╗░██████╗"
echo -e "██╔════╝░██╔════╝████╗░██║██╔════╝██╔════╝██║██╔════╝"
echo -e "██║░░██╗░█████╗░░██╔██╗██║█████╗░░╚█████╗░██║╚█████╗░"
echo -e "██║░░╚██╗██╔══╝░░██║╚████║██╔══╝░░░╚═══██╗██║░╚═══██╗"
echo -e "╚██████╔╝███████╗██║░╚███║███████╗██████╔╝██║██████╔╝"
echo -e "░╚═════╝░╚══════╝╚═╝░░╚══╝╚══════╝╚═════╝░╚═╝╚═════╝░"
echo -e "     █▀▀ ▄▀█ █▀▄▀█ █▀▀   █▀▀ █▄░█ █▀▀ █ █▄░█ █▀▀"
echo -e "     █▄█ █▀█ █░▀░█ ██▄   ██▄ █░▀█ █▄█ █ █░▀█ ██▄"
echo
echo "                  Altxxr0 / CBS"
echo
echo "  Build Starting . . ."
echo

if [[ "$1" == "clean" ]]; then
    echo "Cleaning Build directory . . ."
    if [[ -d Build ]]; then
        rm -rf Build
    fi
fi

if [[ ! -d Build ]]; then
    mkdir Build
fi

cd Build || exit 1

if [[ ! -f CMakeCache.txt ]]; then
    cmake .. | tee ../build_output.txt
fi

cmake --build . --config Debug -- -j4 | tee -a ../build_output.txt

echo

if [[ -d Debug ]]; then
    if [[ -z "$(ls -A Debug)" ]]; then
        echo "  Build Failed <!> - Debug folder is empty."
        echo
        echo "  Relevant Error Lines:"
        echo "  ----------------------"
        grep -i "error" ../build_output.txt || true
        echo "  ----------------------"
        exit 1
    else
        echo "  Build Successful . . ."
    fi
else
    echo "  Build Failed <!> - Debug folder does not exist."
    echo
    echo "  Relevant Error Lines:"
    echo "  ----------------------"
    grep -i "error" ../build_output.txt || true
    echo "  ----------------------"
    exit 1
fi
