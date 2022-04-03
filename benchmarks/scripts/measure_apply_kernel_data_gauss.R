library(scattermore2)

#preload bitmap sizes array
bitmap_sizes = c()
size = 2
while (size <= 1024){
    bitmap_sizes <- append(bitmap_sizes, size)
    size = size * 2
}

bitmap = c()
time = c()
for (bm in bitmap_sizes){
    for(measure in 1:10){  #10 measures
        current_data <- cbind(rnorm(10), rnorm(10)) #data size doesn't matter
        colorized <- colorize_data(current_data, out_size = c(bm, bm))

        t = system.time(apply_kernel_data(colorized))
        bitmap <- append(bitmap, bm)
        time <- append(time, t['elapsed'])
    }
}

df = data.frame(bitmap, time)

saveRDS(df, file="../data/measure_apply_kernel_data_gauss_old.Rda")