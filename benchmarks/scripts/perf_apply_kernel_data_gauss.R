library(cowplot)
library(ggplot2)
library(reshape2)
library(sitools)

df <- readRDS(file="../data/measure_apply_kernel_data_gauss.Rda")
df <- melt(df, id.vars='bitmap', variable.name='method', value.name='time')

df$time <- df$time + 0.001 #zeros correction


ggsave("../plots/perf_apply_kernel_data_gauss.pdf", width = 6, height = 4, units='in',
ggplot(df, aes(bitmap, time, color = method)) +
    geom_point(position = position_jitter(width = 0.1, height = 0)) + # jitter pomaha kdyz je mereni hodne
    geom_smooth(se=F) +
    scale_x_log10("Bitmap dimension", labels = function(x)paste(x,'px')) +
    scale_y_log10("Time", labels = function(x)f2si(x, 's')) +
    ggtitle("Performance of apply_kernel_data") +
    theme_cowplot(font_size = 9) +
    theme(panel.grid.major = element_line(color='#dddddd'))
)