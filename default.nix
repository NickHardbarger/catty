let
  pkgs = import <nixpkgs> { };
in
{
  catty = pkgs.callPackage ./build.nix { };
}
