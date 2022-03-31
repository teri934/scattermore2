library(scattermore2)

#preload bitmap sizes array
bitmap_sizes = c()
size = 2
while (size <= 1024){
    bitmap_sizes <- append(bitmap_sizes, size)
    size = size * 2
}

#preload data sizes array
data_sizes = c()
size = 10
while (size <= 10000000){
    data_sizes <- append(data_sizes, size)
    size = size * 10
}

data = c()
bitmap = c()
time = c()
for (d in data_sizes){
    for (bm in bitmap_sizes){
        current_data <- cbind(rnorm(d), rnorm(d))
        colorized <- colorize_data(current_data, out_size = c(bm, bm))
        t = system.time(apply_kernel_data(colorized))

        data <- append(data, d)
        bitmap <- append(bitmap, bm)
        time <- append(time, t['elapsed'])
    }
}

df = data.frame(data, bitmap, time)

saveRDS(df, file="data/old_gauss.Rda")