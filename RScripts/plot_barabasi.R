# Instalar ggplot2 si no está instalado
if (!require(ggplot2)) install.packages("ggplot2")
if (!require(dplyr)) install.packages("dplyr")

# Cargar las librerías necesarias
library(ggplot2)
library(dplyr)

# Obtener la lista de archivos CSV en el directorio
file_list <- list.files("../data/barabasi", pattern = "*.csv", full.names = TRUE)

# Iterar sobre cada archivo
for (file in file_list) {
  # Cargar el archivo CSV
  data <- read.csv(file, sep = ";")
  
  # Extraer el nombre del archivo sin la extensión
  file_name <- tools::file_path_sans_ext(basename(file))
  
  # Crear el gráfico
  plot <- ggplot(data, aes(x = p, y = connectedGraphsPercentatge, color = as.factor(n))) +
    geom_line(size = 1) +  # Ajustar el grosor de la línea
    geom_point(size = 2) + # Ajustar el tamaño de los puntos
    labs(
      title = paste("Percentatge de grafs Barábasi-Albert connexos segons n i p"),
      x = "Probabilitat de fallida (p)",
      y = "Percentatge de grafs conexos",
      color = "Número de nodes (n)"
    ) +
    scale_color_brewer(palette = "RdBu") +
    theme_minimal()
  
  # Guardar el gráfico como PNG
  # Guardar el gráfico como PNG en el directorio ../data
  ggsave(filename = paste0("../data/barabasi/", file_name, ".png"), bg = "white", plot = plot, width = 8, height = 6)
}