Bing'Optik v2.0
===============
Conçu par Julien VILLEMEJANE et Thierry AVIGNON


Le Bing'Optik est un système permettant de tirer au sort un numéro compris entre 1 et 9 (mode BINGO) qui s'affiche sur un écran LCD. 
Le tout est agrémenté de ruban de LED multicolores.

L'activation du mode BINGO est obtenue en faisant tourner une manivelle (associée à un capteur de position - fourche optique). La détection du mouvement de rotation entraîne à la fois le choix aléatoire d'un nombre sur l'écran LCD et une permutation des couleurs sur les différents bandeaux de LED.
Un mode de veille (SMOOTH) est activé lorsqu'aucun mouvement n'est détecté pendant une vingtaine de secondes. Dans ce mode, la couleur des bandeaux de LED évolue lentement.



Composants
~~~~~~~~~~
- Nucleo F469i-DISCOVERY (avec LCD) : affichage des nombres et gestion des bandeaux de LEDs
- 2 bandeaux de LEDs "intelligentes" de type WS2812
- une fourche optique GP1A51HR
- un bloc d'alimentation de 5V - 5A / 30W


Brochage
~~~~~~~~
D8 / PG10    --> LED Mirroir
D11 / PB15   --> LED Bobine Film
D9 / PA7     --> Random ADC (analogique)
D13 / PD3    --> Entrée Capteur Optique / SYNC


Modes de fonctionnement
~~~~~~~~~~~~~~~~~~~~~~~
Deux modes de fonctionnement :
- SMOOTH : veille du système sans aucun mouvement sur le codeur 
    - défilement lent des couleurs et d'un motif sur les LEDs
    - logo du LEnsE et Bing'Optik sur l'écran avec défilement des couleurs
- BINGO : activé par le codeur optique (mouvement de la roue)
    - défilement sur les LEDs d'un motif "vague"
    - défilement des nombres de 1 à 9 de manière aléatoire sur l'écran

Le passage du mode BINGO au mode SMOOTH se fait automatiquement au bout de 30 secondes environ.
