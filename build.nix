{
  lib,
  stdenv,
  installShellFiles,
  pkg-config,
  gnumake,
  vte,
}:

stdenv.mkDerivation ({
  pname = "catty";
  version = "0.1";

  src = builtins.path {
    name = "build";
    path = ./.;
  };

  nativeBuildInputs = [
    installShellFiles
    pkg-config
    gnumake
  ];

  buildInputs = [ vte ];

  outputs = [ "out" ];

  makeFlags = [
    "PKG_CONFIG=${stdenv.cc.targetPrefix}pkg-config"
    "PREFIX=$(out)"
  ];

  buildPhase = ''
    make clean
    make
  '';

  meta = {
    homepage = "https://github.com/NickHardbarger/catty/";
    description = "A simple, no-frills terminal emulator";
    license = lib.licenses.gpl3Only;
    mainProgram = "catty";
  };
})
