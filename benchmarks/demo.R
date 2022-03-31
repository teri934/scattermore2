library(cowplot)
library(ggplot2)
library(tcltk)

df <- readRDS(file="data/complete_gauss.Rda")

X11()

ggplot() +
    geom_line(data = df, mapping = aes(x = data, y = time, group = bitmap, color = "Not precomputed time")) +
    geom_line(data = df, mapping = aes(x = data, y = precomp_time, group = bitmap, color = "Precomputed time")) +
    facet_grid(rows = vars(bitmap)) +
    scale_y_continuous(sec.axis = sec_axis(~ . , name = "Bitmap dimension (pixels)", breaks = NULL, labels = NULL)) +
    labs(title = "Observed execution of method apply_kernel_data",
         x = "Size of data (number of points)",
         y = "Time (s)",
         color = "Legend") +
    theme(panel.spacing.x = unit(2, "lines"))  #???? co so spacing
    #theme_minimal_grid(12)

prompt  <- "hit spacebar to close plots"
extra   <- "just for visualization"
capture <- tk_messageBox(message = prompt, detail = extra)