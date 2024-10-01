# Cargar el archivo CSV
data <- read.csv("../data/results.csv", sep=";")

# Ver un resumen rápido de los datos
head(data)

# Instalar ggplot2 si no está instalado
if (!require(ggplot2)) install.packages("ggplot2")

# Cargar ggplot2
library(ggplot2)

ggplot(data, aes(x = p, y = connectedGraphs, color = as.factor(n))) +
  geom_line(size = 1) +  # Ajustar el grosor de la línea
  geom_point(size = 2) + # Ajustar el tamaño de los puntos
  labs(
    title = "Número de grafos conexos según n y p",
    x = "Probabilidad de fallo (p)",
    y = "Número de grafos conexos",
    color = "Número de nodos (n)"
  ) +
  theme_minimal()
