#include "../include/tasklist.h"
#include <stdio.h>

static void flush_line(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

int main(void) {
    char cmd;
    struct Node *head = NULL;

    while (1) {
        printf("\nCommande (a/d/t/p/x/s/l/h/q): ");
        if (scanf(" %c", &cmd) != 1) {
            // EOF ou erreur input
            printf("\nFin de l'entrée.\n");
            break;
        }
        flush_line();

        if (cmd == 'a') {
            printf("Entrez id et done (0/1): ");
            int id, done;

            if (scanf("%d %d", &id, &done) != 2) {
                printf("Format invalide\n");
                flush_line();
            } else {
                flush_line();

                if (done != 0 && done != 1) {
                    printf("Erreur: done doit être 0 ou 1\n");
                } else if (find_by_id(head, id) != NULL) {
                    printf("Erreur: id déjà existant\n");
                } else {
                    if (!push_back(&head, id, done)) {
                        printf("Erreur mémoire\n");
                    } else {
                        printf("Ajouté.\n");
                    }
                }
            }
        }

        else if (cmd == 'd') {
            printf("Entrez id: ");
            int id;

            if (scanf("%d", &id) != 1) {
                printf("Format invalide\n");
                flush_line(); 
            } else {
                flush_line();

                if (!delete_by_id(&head, id)) {
                    printf("Cette tâche n'existe pas dans la liste.\n");
                } else {
                    printf("Supprimé.\n");
                }
            }
        }

        else if (cmd == 't') {
            printf("Entrez un id: ");
            int id;

            if (scanf("%d", &id) != 1) {
                printf("Format invalide\n");
                flush_line(); 
            } else {
                flush_line(); 

                if (!toggleDone(head, id)) {
                    printf("Cette tâche n'existe pas dans la liste.\n");
                } else {
                    printf("Statut inversé.\n");
                }
            }
        }

        else if (cmd == 'x') {
            int total, done;
            get_stats(head, &total, &done);

            if (total > 0) {
                double percent = (double)done * 100.0 / (double)total;
                printf("Total: %d\n", total);
                printf("Done: %d\n", done);
                printf("Completion: %.2f%%\n", percent);
            } else {
                printf("Il n'y a pas de tâche dans la liste.\n");
            }
        }

        else if (cmd == 's') {
            printf("Entrez nom fichier: ");
            char filename[100];

            if (scanf("%99s", filename) != 1) {
                printf("Format invalide\n");
                flush_line();  
            } else {
                flush_line(); 

                if (!save_list(filename, head)) {
                    printf("Erreur durant la sauvegarde.\n");
                } else {
                    printf("Sauvegarde réussie.\n");
                }
            }
        }

        else if (cmd == 'l') {
            printf("Entrez nom fichier: ");
            char filename[100];

            if (scanf("%99s", filename) != 1) {
                printf("Format invalide\n");
                flush_line(); 
            } else {
                flush_line(); 
                if (!load_list(filename, &head)) {
                    printf("Erreur durant le chargement.\n");
                } else {
                    printf("Chargement réussi.\n");
                }
            }
        }

        else if (cmd == 'p') {
            print_list(head);
        }

        else if (cmd == 'h') {
            printf(
                "\nCommandes disponibles :\n"
                "a → ajouter (a puis: id done)\n"
                "d → supprimer (d puis: id)\n"
                "t → toggle done (t puis: id)\n"
                "p → afficher la liste\n"
                "x → statistiques\n"
                "s → sauvegarder (s puis: nomfichier)\n"
                "l → charger (l puis: nomfichier)\n"
                "h → aide\n"
                "q → quitter\n"
            );
        }

        else if (cmd == 'q') {
            break;
        }

        else {
            printf("Commande inconnue. Tape 'h' pour l'aide.\n");
        }
    }

    free_list(&head);
    return 0;
}
