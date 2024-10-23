# Cargar librerías necesarias
library(dplyr)
library(ggplot2)

# Leer el CSV
data <- read.csv("../data/square/squareE-20-200.csv", sep = ";", header = TRUE)

# Obtener valores únicos de n
unique_n <- unique(data$n)

# Inicializar una lista para almacenar resultados y un vector para el texto
threshold_results <- list()
output_lines <- c()

# Cabecera de la tabla
header <- "$N$ & Threshold $p$ & Porcentaje Conectado & Tasa de Cambio\n"
output_lines <- c(output_lines, header)

# Iterar sobre cada valor único de n
for (n_value in unique_n) {
  
  # Filtrar los datos para el valor actual de n
  data_n <- data %>% filter(n == n_value)
  
  # Calcular la tasa de cambio del porcentaje de gráficos conectados
  data_n <- data_n %>%
    mutate(diff_connected = c(NA, diff(connectedGraphsPercentatge)),
           diff_p = c(NA, diff(p)),  # Calcular la diferencia de p
           rate_of_change = diff_connected / diff_p)  # Dividir por la diferencia de p
  
  # Eliminar NA para que el tamaño coincida
  data_n <- na.omit(data_n)
  
  # Identificar el umbral donde la tasa de cambio es máxima
  if (nrow(data_n) > 0) {
    threshold_index <- which.max(abs(data_n$rate_of_change))
    threshold_p <- data_n$p[threshold_index]
    
    # Almacenar resultados
    threshold_results[[as.character(n_value)]] <- list(
      threshold_p = threshold_p,
      connected_percentage = data_n$connectedGraphsPercentatge[threshold_index],
      rate_of_change = data_n$rate_of_change[threshold_index]
    )
    
    # Formatear el resultado y agregarlo al vector de salida
    output_lines <- c(output_lines, sprintf("%d & %.2f & %.2f & %.2f\n", 
                                            n_value, 
                                            threshold_p, 
                                            data_n$connectedGraphsPercentatge[threshold_index], 
                                            data_n$rate_of_change[threshold_index]))
  }
}

# Imprimir todo al final
cat(paste(output_lines, collapse = ""))
