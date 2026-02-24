# TaskBox – Gestionnaire de tâches en C
## Description
TaskBox est un gestionnaire de tâches en ligne de commande développé en C.
Il permet d’ajouter, supprimer, modifier, sauvegarder et charger des tâches à partir d’un fichier.

Ce projet a été réalisé afin de consolider les bases en programmation C, notamment la gestion mémoire dynamique, la manipulation de pointeurs simples et doubles, la modularité du code et la robustesse des entrées utilisateur.

## Choix de la structure de données

La structure principale utilisée est une liste chaînée simplement liée car : 

 - Un nombre de tâches inconnu à l’avance.
 - Une gestion dynamique naturelle via malloc et free.
 - Des insertions et suppressions simplifiées sans redimensionnement
   global.
 - Un objectif pédagogique centré sur la manipulation explicite des
   pointeurs.

La suppression d’un élément (delete_by_id) est notamment plus simple à implémenter qu’avec un tableau dynamique, où un décalage des éléments serait nécessaire.

## Architecture du projet

Le projet est structuré en trois parties :

   ```markdown
    include/tasklist.h   → déclarations des structures et prototypes
    src/tasklist.c       → implémentation des fonctions de gestion de la liste
    src/main.c           → interface utilisateur (CLI)
   ```

Cette séparation permet :

  - D’isoler la logique métier de l’interface.
 - De modifier l’implémentation sans impacter main.c.
- De respecter un principe d’abstraction similaire aux bibliothèques standards du C.

## Fonctionnalités
Commandes disponibles :

    a → ajouter une tâche
    d → supprimer une tâche
    t → inverser l’état (done)
    p → afficher la liste
    x → afficher les statistiques
    s → sauvegarder dans un fichier
    l → charger depuis un fichier
    h → afficher l’aide
    q → quitter

## Complexité des opérations

| Fonction       | Complexité |
| -------------- | ---------- |
| `push_back`    | O(n)       |
| `find_by_id`   | O(n)       |
| `delete_by_id` | O(n)       |
| `toggleDone`   | O(n)       |
| `get_stats`    | O(n)       |
| `save_list`    | O(n)       |
| `load_list`    | O(n)       |

La complexité est linéaire car chaque opération nécessite un parcours de la liste.

## Gestion mémoire
    - Chaque tâche est allouée dynamiquement avec malloc.
    - La mémoire est libérée explicitement via free.
    - free_list garantit qu’aucune fuite mémoire ne subsiste.
    - load_list nettoie correctement la liste en cas d’erreur d’allocation.

Le projet est compilé avec

`-Wall -Wextra -Wpedantic -fsanitize=address`

et ne génère aucun warning.

## Compilation
Compilation : 

`make`

Exécution:

`make run` 

Nettoyage : 

`make clean`

## Ce que j’ai appris
 - Manipulation de pointeurs simples et doubles (Node * vs Node **).
- Gestion mémoire dynamique en C.
- Prévention des fuites mémoire.
- Gestion robuste des entrées utilisateur (scanf + nettoyage du buffer).
- Séparation interface / implémentation via fichiers .h et .c.
- Automatisation de la compilation avec un Makefile.

## Améliorations possibles
- Utiliser une table de hachage pour un accès en O(1).
- Implémenter un tri automatique des tâches.
- Ajouter des tests unitaires.
- Remplacer scanf par fgets pour un parsing encore plus robuste.