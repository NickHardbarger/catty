let
  pkgs = import <nixpkgs> { };
in
{
  catty = pkgs.CallPackage ./build.nix { };
}
