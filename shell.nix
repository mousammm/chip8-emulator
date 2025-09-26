{ pkgs ? import <nixpkgs> {}}:

pkgs.mkShell {
  name = "chip8 dev enviroment";

  buildInputs = with pkgs; [
    gcc 
    gnumake
    SDL2
  ];

  shellHook = ''
    echo "gcc/make/SDL2 available!"
    echo "Dev enviroment setup!"
  '';
}
