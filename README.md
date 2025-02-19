# Get Next Line - Lecture de fichier ligne par ligne

Une fonction en C qui permet de lire le contenu d'un fichier ligne par ligne à partir d'un descripteur de fichier.

## 📝 Description

Get Next Line (GNL) est une fonction qui lit une ligne depuis un descripteur de fichier. Elle est particulièrement utile pour la lecture séquentielle de fichiers texte et l'entrée standard.

## 🛠️ Fonctionnalités

### Prototype
```c
char *get_next_line(int fd);
```

### Caractéristiques
- Lecture ligne par ligne depuis un descripteur de fichier
- Gestion de différentes tailles de buffer via BUFFER_SIZE
- Retourne NULL en fin de fichier ou en cas d'erreur
- Conserve le \n final sauf pour la dernière ligne si elle n'en a pas

## 📚 Structure du Projet

| Fichier | Description |
|---------|-------------|
| get_next_line.c | Fonction principale |
| get_next_line.h | Header et prototypes |
| get_next_line_utils.c | Fonctions utilitaires |


## ⚠️ Restrictions

- Pas de libft autorisée
- Pas de lseek()
- Pas de variables globales
- Gestion de la mémoire rigoureuse (pas de leaks)

## 🔍 Tests Recommandés

- Différentes tailles de BUFFER_SIZE
- Fichiers de différentes tailles
- Lecture depuis l'entrée standard
- Gestion des erreurs
- Tests de performance

---
*Projet réalisé dans le cadre du cursus de l'école 42*
