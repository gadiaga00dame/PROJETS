parse_geo_data_from_arcgis <- function(url, parameters) {
  # Libraries
  library(httr)
  library(jsonlite)
  
  # Send a GET request to the API
  url_to_parse <- paste0(url, parameters)
  response <- GET(url_to_parse)
  
  # Parse the JSON response
  content_text <- content(response, "text")
  
  # Try to parse the content as JSON
  data <- tryCatch({
    fromJSON(content_text)
  }, error = function(e) {
    stop("Failed to parse JSON: ", e$message)
  })
  
  # Check for exceeded transfer limit
  if ("exceededTransferLimit" %in% names(data) && data$exceededTransferLimit == TRUE) {
    stop("Row threshold is reached. Please check the query.")
  } else {
    print("Great, row threshold is not reached.")
  }
  
  # Flatten the JSON data using jsonlite::flatten
  if ("features" %in% names(data)) {
    flattened_data <- jsonlite::flatten(data$features)
  } else {
    stop("No features found in the data.")
  }
  
  return(flattened_data)
}

# Example usage
url <- "https://geoweb.iau-idf.fr/agsmap1/rest/services/OPENDATA/OpendataIAU1/MapServer/6/"
parameters2022 <- "query?where=1%3D1&outFields=*&outSR=4326&f=json"
flatdata <- parse_geo_data_from_arcgis(url, parameters2022)
flatdata

library(tidyverse)

flatdata <- flatdata %>%
  mutate(
    x = geometry.x,
    y = geometry.y
  )

library(leaflet) 
leaflet(flatdata) %>%
  addTiles() %>%
  addMarkers(lng = ~x, lat = ~y, popup = "Localisation !")

leaflet(flatdata) %>%
  addTiles() %>%
  addMarkers(lng = ~x, lat = ~y, 
             popup = paste0("Nom : ",flatdata$attributes.nom,", Adresse : ",flatdata$attributes.adresse))


leaflet(flatdata) %>%
  addTiles() %>%
  addMarkers(lng = ~x, lat = ~y, 
             popup = paste0("Nom : ",flatdata$attributes.nom,", Adresse : ",flatdata$attributes.adresse),
             clusterOptions = markerClusterOptions())


# Filtrer les cinémas avec plus de 2000 fauteuils
cinemas <- subset(flatdata, attributes.fauteuils > 2000)

# Créer la carte Leaflet
leaflet(cinemas) %>%
  addTiles() %>%
  addCircleMarkers(
    lng = ~ x,  
    lat = ~ y,   
    popup = paste0("Nom:", cinemas$attributes.nom,
                   "<br>Adresse:", cinemas$attributes.adresse,
                   "<br>Fauteuils:", cinemas$attributes.fauteuils),
    
    radius = ~ifelse(attributes.fauteuils >= 2000, 5),
    color = "blue",
    
    stroke = FALSE, fillOpacity = 0.5
  )
