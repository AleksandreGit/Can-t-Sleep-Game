# Can't Sleep - The Game

Voir ma chaîne Youtube pour suivre l'évolution du projet: https://www.youtube.com/channel/UCv9v0MaEkK0Lq-3QQ-zr8mA

## 1) Introduction:

  L'origine de ce projet date du *20 Décembre 2020*, date à laquelle nous avons décidé avec plusieurs amis de nous lancer dans un projet de GameJam. Le sujet conservé était ***"Créatures de la nuit"*** et nous avions les vacances de Noël pour travailler sur le projet.
  
  Ayant envie d'améliorer mes compétences en C++, j'ai naturellement choisi ce langage afin de créer mon jeu et j'ai décidé de l'utiliser avec la librairie SFML.
  
  Au terme de cette GameJam, mon projet était très loin d'avoir été terminé, seulement le principe avait été développé. Profitant du temps libre dont je dispose lors de mon voyage Erasmus à l'université de Lulea (en Suède), j'ai décidé de continuer ce projet pour voir jusqu'où cela va me mener.

## 2) Concept du jeu:
  
  Le sujet annoncé m'a donné une idée de Gameplay toute simple: un cycle jour/nuit avec des attaques de créatures la nuit. A partir de ceci, je suis venu étoffer avec davantages d'idées : système basique de récolte de ressources, système basique de craft, permettre des constructions de défense, etc.
  
  L'objectif du jeu serait donc le jour de récolter des ressources afin de construire des systèmes de défense en prévision des attaques de la nuit. Au fur et à mesure que les jours passent, il faudra faire face à des vagues plus virulentes, il faudra donc améliorer ses défenses en conséquence. 

## 3) Etat actuel du jeu:

Version actuelle du jeu: Dev. 0.3 (**Construction MAJ**)
(Mis à jour 24 Mars 2021)
Actuellement les fonctionnalités suivantes ont étés mises en place:

- Animations basique de personnage
- Déplacement de personnage
- Génération de carte procédurale classique
- Interaction basique avec environnement (destruction d'arbres, rochers, ...)
- Mise en place de l'UI de l'inventaire
- Possibilité de changer d'item
- Mise en place du drop d'objets
- Mise en place du ramassage des objets
- Possibilité de détruire des arbres/récolter des ressources
- Drag and drop avec la barre d'outils
- Mettre en place les effets d'items
- Prémices de la construction: 
	- Afficher l'objet sur carte en transparence lorsque tenu en main
	- Posage de l'objet lorsque clic
	- Possibilité de casser l'objet
	- Ramassage de l'objet et cassage à nouveau

## 4) Feature en cours de dev
- Prémices du craft

## 5) Bugs détectés actuels 
NONE

## 6) Prochains ajouts
- Cycle jour et nuit
- Ajout premier ennemi
- Test
- Correction de bugs
- Refactoring de code
- ....
(Autres idées à venir)

## 7) Idées d'amélioration 
- Temps d'attente avant ramassage des objets au sol
- Affichage de l'objet lorsqu'il est drag
- Utilisation Flyweight pour Constructible/Item pour permettre double compo ?
- Entity Component System ?
