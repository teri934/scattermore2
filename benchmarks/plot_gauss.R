library(cowplot)
library(ggplot2)
library(tcltk)

df <- readRDS(file="data/complete_gauss.Rda")

X11()

ggplot() +
    geom_line(data = df, mapping = aes(x = bitmap, y = time, color = "Not precomputed time")) +
    geom_line(data = df, mapping = aes(x = bitmap, y = precomp_time, color = "Precomputed time")) +
    labs(title = "Observed execution of method apply_kernel_data",
         x = "Bitmap dimension (pixels)",
         y = "Time (s)",
         color = "Legend") +
    theme_minimal_grid(12)

prompt  <- "hit spacebar to close plots"
extra   <- "just for visualization"
capture <- tk_messageBox(message = prompt, detail = extra)