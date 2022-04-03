library(scattermore2)

#use premade data frame to add times with precomputed data
df <- readRDS(file="../data/measure_apply_kernel_data_gauss_old.Rda")

precomp_time = c()
for (bm in df['bitmap']){
    for(measure in 1:10){
        #current_data <- cbind(rnorm(1000), rnorm(1000)) #data size doesn't matter
        #colorized <- colorize_data(current_data, out_size = c(bm, bm))

        #t = system.time(apply_kernel_data(colorized))
        bitmap <- append(bitmap, bm)
        precomp_time <- append(precomp_time, 0.5)
    }
}

df_new <- cbind(df, precomp_time)

saveRDS(df_new, file="../data/measure_apply_kernel_data_gauss.Rda")