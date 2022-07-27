Pour WINDOWS:

-- SFML VERSION 2.4.2 32 BITS REQUISE:
    https://www.sfml-dev.org/download/sfml/2.4.2/

-- IRRLICHT 1.8.4 (version 32 BITS REQUISE):
    http://irrlicht.sourceforge.net/?page_id=10

-- Modifier dans CMakeList.txt :

CMAKE_MODULE_PATH "Chemin du dossier irrlicht" (exemple: "C:/Users/NeoMarvin/Desktop/irrlicht-1.8.4")
Irrlicht_DIR "Chemin du dossier irrlicht/lib/Win32-visualstudio" (exemple: "C:/Users/NeoMarvin/Desktop/irrlicht-1.8.4/lib/Win32-visualstudio")


CMAKE_SFML_PATH "Chemin du dossier SFML" (exemple: "C:/Users/NeoMarvin/Desktop/SFML-2.4.2")
SFML_ALL_INCLUDES_DIRS "Chemin du dossier SFML/include" (exemple: "C:/Users/NeoMarvin/Desktop/SFML-2.4.2/include")


Pour LINUX:

-- IRRLICHT: Installer la librairie Irrlicht via le gestionnaire de paquet de votre OS

-- SFML: Installer la libraire SFML (version 2.4.2 REQUISE) via le gestionnaire de paquet de votre OS



BUGS CONNUS (et totalement assumés):

-- Possible cliping dans la map si jamais le joueur
   se déplace dans un mur lors de l'explosion d'une bombe.


SPECIFITES (entre les 2 OS):

WINDOWS --> La sauvegarde n'est pas supporté, le bouton "Continuer" sera donc toujours vérouillé
WINDOWS --> L'utilisation de la musique sur Windows causant plusieurs problèmes nous avons décidé
            d'enlever celle-ci du jeu.

LINUX --> Toutes altérations du fichier de sauvegarde empêchera le jeu de bien se charger,
          veuillez par conséquent ne pas modifier les données se trouvant dans le fichier.
