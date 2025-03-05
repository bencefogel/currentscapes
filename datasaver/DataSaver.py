import os
import pandas as pd
import numpy as np

class DataSaver:
    """
    A class for saving large DataFrames in chunks to manage memory usage efficiently.

    Args:
        columns_in_chunk (int): Number of columns per chunk when saving data.
    """
    def __init__(self, columns_in_chunk: int) -> None:
        self.columns_in_chunk = columns_in_chunk

    def save_in_chunks(self, data: pd.DataFrame, output: str):
        """
        Saves the data in chunks as .npy files along with a CSV file for the MultiIndex.

        The method splits the DataFrame into smaller chunks by columns and saves each chunk as
        a .npy file in the specified output directory. It also saves the DataFrame's MultiIndex
        to a CSV file to ensure data consistency during loading.

        Args:
            data (pd.DataFrame): The DataFrame containing data to be saved. Must have a MultiIndex.
            output (str): The directory where the chunks and index file will be saved.
        """
        if not os.path.exists(output):
            os.makedirs(output)

        values = data.values.astype(np.float32)

        # If no chunk_size is provided, save the whole array in one file
        if self.columns_in_chunk is None:
            self.columns_in_chunk = values.shape[1]

        num_chunks = values.shape[1] // self.columns_in_chunk + (1 if values.shape[1] % self.columns_in_chunk != 0 else 0)

        index_saved = False
        for i in range(num_chunks):
            start_idx = i * self.columns_in_chunk
            end_idx = min((i + 1) * self.columns_in_chunk, values.shape[1])

            chunk_values = values[:, start_idx:end_idx]

            chunk_file = os.path.join(output, f"current_values_{i}.npy")
            np.save(chunk_file, chunk_values)

            if not index_saved:
                index = data.index.to_frame().reset_index(drop=True)
                index_output_file = os.path.join(output, 'multiindex.csv')
                index.to_csv(index_output_file, index=False)
                index_saved = True

